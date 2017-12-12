#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 12;
char g[mx][mx];
bool whiteVisited[mx][mx], blackVisited[mx][mx];
int n = 9;
int black, white, toAdd;
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    black = white = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            whiteVisited[i][j] = blackVisited[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        cin >> g[i];
    }
}

char rev(char color){
    if(color == 'X') return 'O';
    return 'X';
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < n);
}

void dfs(int i, int j, char color){
    if(color == 'X') blackVisited[i][j] = true;
    if(color == 'O') whiteVisited[i][j] = true;

    for(int k = 0; k < 4; ++k){
        int newI = i + x[k];
        int newJ = j + y[k];
        if(valid(newI, newJ) and g[newI][newJ] != rev(color)){
            if(color == 'X' and !blackVisited[newI][newJ]) dfs(newI, newJ, color);
            if(color == 'O' and !whiteVisited[newI][newJ]) dfs(newI, newJ, color);
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(g[i][j] != '.'){
                dfs(i, j, g[i][j]);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(blackVisited[i][j] and !whiteVisited[i][j]) ++black;
            if(whiteVisited[i][j] and !blackVisited[i][j]) ++white;
        }
    }
}

void print(){
    cout << "Black " << black << " White " << white << endl;
}

int main()
{
    //file();

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        scan();
        reset();
        solve();
        print();
    }

    return 0;
}
