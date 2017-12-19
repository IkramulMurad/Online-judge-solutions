#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 2005;
bool g[mx][mx], tg[mx][mx];
bool visited[mx];
int stk[mx], top;
int n, m, kount;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void clr(){
    for(int i = 0; i < mx; ++i){
        visited[i] = false;
    }
}

void reset(){
    clr();
    kount = top = 0;

    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            g[i][j] = tg[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < m; ++i){
        int u, v, type;
        cin >> u >> v >> type;

        g[u][v] = true;
        tg[v][u] = true;

        if(type == 2){
            g[v][u] = true;
            tg[u][v] = true;
        }
    }
}

void dfs(int u){
    visited[u] = true;

    for(int v = 1; v <= n; ++v){
        if(g[u][v] and !visited[v]){
            dfs(v);
        }
    }

    stk[top++] = u;
}

void dfs2(int u){
    visited[u] = true;

    for(int v = 1; v <= n; ++v){
        if(tg[u][v] and !visited[v]){
            dfs2(v);
        }
    }
}

void solve(){
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            dfs(i);
        }
    }

    clr();
    for(int i = top - 1; i >= 0; --i){
        int u = stk[i];
        if(!visited[u]){
            ++kount;
            dfs2(u);
        }
    }
}

void print(){
    if(kount == 1) cout << 1 << endl;
    else cout << 0 << endl;
}

int main()
{
    //file();

    while(cin >> n >> m and (n or m)){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
