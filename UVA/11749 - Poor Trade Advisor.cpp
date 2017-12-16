#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;
const int mx = 505;
const LL mn = -1e12;
LL g[mx][mx];
bool visited[mx];
LL ppa, ans, kount, n, m;

void fileio(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

LL max(LL x, LL y){
    if(x > y) return x;
    return y;
}

void reset(){
    ans = 0;
    ppa = mn;
    for(int i = 0; i < mx; ++i){
        visited[i] = false;
        for(int j = 0; j < mx; ++j){
            g[i][j] = mn;
        }
    }
}

void scan(){
    for(int i = 0; i < m; ++i){
        LL u, v, w;
        cin >> u >> v >> w;

        ppa = max(ppa, w);
        g[u][v] = g[v][u] = max(g[u][v], w);
    }
}

bool valid(int u){
    for(int v = 1; v <= n; ++v){
        if(g[u][v] == ppa) return true;
    }
    return false;
}

void dfs(int u){
    visited[u] = true;
    ++kount;

    for(int v = 1; v <= n; ++v){
        if(!visited[v] and g[u][v] == ppa){
            dfs(v);
        }
    }
}

void solve(){
    for(int i = 1; i <= n; ++i){
        if(valid(i) and !visited[i]){
            kount = 0;
            dfs(i);
            ans = max(ans, kount);
        }
    }
}

void print(){
    cout << ans << endl;
}

int main()
{
    //fileio();

    while(cin >> n >> m and (n or m)){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
