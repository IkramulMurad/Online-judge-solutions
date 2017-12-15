#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 305;
int n;
bool g[mx][mx];
bool visited[mx], color[mx];
bool impossible;

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
        visited[i] = color[i] = false;
    }
    impossible = false;
}

void scan(){
    int u, v;
    while(cin >> u >> v and (u or v)){
        g[u][v] = g[v][u] = true;
    }
}

void dfs(int u, bool col){
    visited[u] = true;
    color[u] = col;

    for(int v = 1; v <= n; ++v){
        if(g[u][v] and !visited[v]){
            dfs(v, !col);
        }
    }
}

void solve(){
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            dfs(i, 0);
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(g[i][j] and color[i] == color[j]){
                impossible = true;
            }
        }
    }
}

void print(){
    if(impossible) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main()
{
    //fileInput();

    while(cin >> n and n){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
