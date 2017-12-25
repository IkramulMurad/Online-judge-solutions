#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 12;
char g[mx][mx];
int point[mx][mx];
int loopSize, kount;
int n, m, x, y;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    loopSize = kount = x = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            point[i][j] = 0;
        }
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        cin >> g[i];
    }
}

void move(char dir){
    if(dir == 'N') --x;
    if(dir == 'S') ++x;
    if(dir == 'E') ++y;
    if(dir == 'W') --y;
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void solve(){
    --y;
    while(valid(x, y)){
        ++kount;
        if(!point[x][y]){
            point[x][y] = kount;
        }
        else{
            loopSize = kount - point[x][y];
            break;
        }

        move(g[x][y]);
    }
}

void print(){
    if(loopSize) cout << kount - loopSize - 1 << " step(s) before a loop of " << loopSize << " step(s)" << endl;
    else cout << kount << " step(s) to exit" << endl;
}

int main()
{
    //file();

    while(cin >> n >> m >> y and (n or m or y)){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
