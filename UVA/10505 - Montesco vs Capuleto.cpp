#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 205;
int n;
int ans, kount, kount2;
bool g[mx][mx];
bool visited[mx], color[mx];
bool impossible;

void fileIO(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    ans = 0;
    for(int i = 0; i < mx; ++i){
        visited[i] = color[i] = false;
        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

int max(int x, int y){
    if(x > y) return x;
    return y;
}

void dfs(int u, bool col){
    visited[u] = true;
    color[u] = col;

    if(col) ++kount;
    else ++kount2;

    for(int v = 1; v <= n; ++v){
        if(g[u][v] and !visited[v]){
            dfs(v, !col);
        }
    }

    for(int v = 1; v <= n; ++v){
        if(g[u][v] and col == color[v]) impossible = true;
    }
}

void solve(){
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            kount = kount2 = 0;
            impossible = false;

            dfs(i, false);
            if(!impossible) ans += max(kount, kount2);
        }
    }
}

void scan(){
    cin >> n;

    for(int u = 1; u <= n; ++u){
        int m;
        cin >> m;

        for(int j = 0; j < m; ++j){
            int v;
            cin >> v;

            if(v > n) continue;

            g[u][v] = g[v][u] = true;
        }
    }
}

void print(){
    cout << ans << endl;
}

int main()
{
    //fileIO();

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
