#include <iostream>
#include <stdio.h>

using namespace std;

const int mx = 25 + 5;
int m, ans;
char g[mx][mx];
bool visited[mx][mx];
int x[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int y[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void clr(){
    ans = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < m; ++i){
        cin >> g[i];
    }
}

bool valid(int i, int j){
    if(i >= 0 and j >= 0 and i < m and j < m){
        return true;
    }
    return false;
}

void dfs(int i, int j){
    visited[i][j] = true;
    for(int k = 0; k < 8; ++k){
        int newI = i + x[k], newJ = j + y[k];
        if(valid(newI, newJ) and !visited[newI][newJ] and g[newI][newJ] == '1'){
            dfs(newI, newJ);
        }
    }
}

void solve(){
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j] and g[i][j] == '1'){
                ++ans;
                dfs(i, j);
            }
        }
    }
}

void print(int tc){
    cout << "Image number " << tc << " contains " << ans << " war eagles." << endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc = 0;
    while(cin >> m){
        clr();
        scan();
        solve();
        print(++tc);
    }
    return 0;
}
