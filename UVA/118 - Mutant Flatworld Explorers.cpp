#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
bool g[mx][mx];
int n, m, idx, x, y;
bool lost;
char ori[] = "NESW";

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

void scan(){
    cin >> n >> m;
    ++n; ++m;
}

int getIdx(char ch){
    int i;
    for(i = 0; i < 4; ++i){
        if(ori[i] == ch) break;
    }
    return i;
}

bool valid(int i, int j){
    if(i >= 0 and j >= 0 and i < n and j < m) return true;

    lost = true;
    return false;
}

void move(){
    if(ori[idx] == 'N'){
        if(valid(x, y + 1)) ++y;
        else if(g[x][y]) lost = false;
        else g[x][y] = true;
    }
    if(ori[idx] == 'S'){
        if(valid(x, y - 1)) --y;
        else if(g[x][y]) lost = false;
        else g[x][y] = true;
    }
    if(ori[idx] == 'W'){
        if(valid(x - 1, y)) --x;
        else if(g[x][y]) lost = false;
        else g[x][y] = true;
    }
    if(ori[idx] == 'E'){
        if(valid(x + 1, y)) ++x;
        else if(g[x][y]) lost = false;
        else g[x][y] = true;
    }
}

void execute(char command){
    if(command == 'F'){
        move();
    }
    else if(command == 'R'){
        idx = (idx + 1) % 4;
    }
    else if(command == 'L'){
        idx = (idx - 1 + 4) % 4;
    }
    cerr << x << " " << y << " " << ori[idx] << endl;
}

void print(){
    cout << x << " " << y << " " << ori[idx];
    if(lost) cout << " " << "LOST";
    cout << endl;
}

void solve(){
    char orient, instructions[mx];
    while(cin >> x >> y >> orient >> instructions){
        lost = false;
        idx = getIdx(orient);
        for(int i = 0; instructions[i]; ++i){
            if(!lost) execute(instructions[i]);
        }
        print();
    }
}

int main(){
    //file();

    reset();
    scan();
    solve();

    return 0;
}
