#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 30;
int n, m;
int g[mx][mx];
bool taken[mx][mx];

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void init(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            taken[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            g[i][j] = 0;
        }
    }

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
}

int max(int x, int y){
    if(x > y) return x;
    return y;
}

int dfs(int u){
    int cmax = 0;
    for(int v = 0; v < n; ++v){
        if(g[u][v] and !taken[u][v]){
            taken[u][v] = taken[v][u] = true;
            cmax = max(cmax, 1 + dfs(v));
            taken[u][v] = taken[v][u] = false;
        }
    }
    return cmax;
}

int main()
{
    //fileInput();

    while(cin >> n >> m and (n or m)){
        scan();

        int ans = 0;
        for(int i = 0; i < n; ++i){
            init();
            ans = max(ans, dfs(i));
        }
        cout << ans << endl;
    }

    return 0;
}
