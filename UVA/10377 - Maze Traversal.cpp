#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
char g[mx][mx];
int n, m, idx, x, y;
char ori[] = "NESW";

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void scan(){
    cin >> n >> m;
    getchar();
    for(int i = 0; i < n; ++i) gets(g[i]);

    cin >> x >> y;
    --x; --y;
    getchar();
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m and g[i][j] != '*');
}

void move(){
    if(ori[idx] == 'N' and valid(x - 1, y)) --x;
    if(ori[idx] == 'S' and valid(x + 1, y)) ++x;
    if(ori[idx] == 'W' and valid(x, y - 1)) --y;
    if(ori[idx] == 'E' and valid(x, y + 1)) ++y;
}

void execute(char command){
    if(command == 'F'){
        move();
    }
    else if(command == 'R'){
        idx = (idx + 1 + 4) % 4;
    }
    else if(command == 'L'){
        idx = (idx - 1 + 4) % 4;
    }
    //cerr << x + 1 << " " << y + 1 << " " << ori[idx] << endl;
}

void solve(){
    idx = 0;

    char ch;
    while(true){
        cin >> ch;
        if(ch == 'Q') break;

        if(ch == 'F' or ch == 'R' or ch == 'L') execute(ch);
    }
}

void print(){
    cout << x + 1 << " " << y + 1 << " " << ori[idx] << endl;
}

int main(){
    //file();

    int tc;
    cin >> tc;
    while(tc--){
        scan();
        solve();
        print();
        if(tc) cout << endl;
    }

    return 0;
}
