#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
char g[mx][mx];
int n, m, s, ans, idx, x, y;
char seq[50005];
char ori[] = "NLSO";

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void scan(){
    for(int i = 0; i < n; ++i) cin >> g[i];
    cin >> seq;
}

int getIdx(char ch){
    int i;
    for(i = 0; ch != ori[i]; ++i){}
    return i;
}

void changeOri(char command){
    if(command == 'D') idx = (idx + 1 + 4) % 4;
    else idx = (idx - 1 + 4) % 4;
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m and g[i][j] != '#');
}

void move(){
    if(ori[idx] == 'N' and valid(x - 1, y)) --x;
    if(ori[idx] == 'S' and valid(x + 1, y)) ++x;
    if(ori[idx] == 'O' and valid(x, y - 1)) --y;
    if(ori[idx] == 'L' and valid(x, y + 1)) ++y;

    if(g[x][y] == '*'){
        ++ans;
        g[x][y] = '.';
    }
}

void execute(char command){
    if(command == 'F'){
        move();
    }
    else{
        changeOri(command);
    }
}

void solve(){
    ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(g[i][j] != '.' and g[i][j] != '*' and g[i][j] != '#'){
                idx = getIdx(g[i][j]);
                x = i; y = j;
            }
        }
    }

    for(int i = 0; i < s; ++i){
        execute(seq[i]);
    }
}

void print(){
    cout << ans << endl;
}

int main(){
    //file();

    while(cin >> n >> m >> s and (n or m or s)){
        scan();
        solve();
        print();
    }

    return 0;
}
