#include <iostream>
#include <stdio.h>
using namespace std;

const int mx = 200 + 5;
char g[mx][mx];
bool visited[mx][mx];
bool jobDone, blackWin;
int n;
int x[] = {-1, -1, 0, 0, 1, 1};
int y[] = {-1, 0, -1, 1, 0, 1};

void clr(){
    jobDone = false;
    blackWin = false;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            visited[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        cin >> g[i];
    }
}

bool valid(int i, int j){
    if(i >= 0 and j >= 0 and i < n and j < n){
        return true;
    }
    return false;
}

void dfs(int i, int j){
    visited[i][j] = true;
    for(int k = 0; k < 6; ++k){
        int newI = i + x[k];
        int newJ = j + y[k];
        if(valid(newI, newJ) and g[newI][newJ] == 'b' and !visited[newI][newJ] and !jobDone){
            if(newI == n-1){
                jobDone = true;
                blackWin = true;
                return;
            }
            dfs(newI, newJ);
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        if(g[0][i] == 'b' and !visited[0][i] and !jobDone){
            dfs(0, i);
        }
    }
}

void print(int tc){
    cout << tc << " ";
    if(blackWin) cout << 'B' << endl;
    else cout << 'W' << endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc = 0;
    while(cin >> n and n){
        clr();
        scan();
        solve();
        print(++tc);
    }
    return 0;
}
