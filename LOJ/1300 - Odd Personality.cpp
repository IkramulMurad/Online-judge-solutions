#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> II;
const int mx = 1e4 + 5;
const int inf = 1e9;
vector<vector<int> > g(mx);
set<II> ab;
bool visited[mx];
int parent[mx], d[mx], low[mx], color[mx];
int ans, second, n, m;
bool found;
 
void reset(){
    for(int i = 0; i < mx; ++i){
        g[i].clear();
        visited[i] = false;
 
        parent[i] = -1;
        d[i] = low[i] = 0;
    }
    ans = second = 0;
    ab.clear();
}
 
void scan(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
 
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
 
void print(int t){
    printf("Case %d: %d\n", t, ans);
}
 
void dfs(int u){
    visited[u] = true;
    d[u] = low[u] = ++second;
 
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
 
        if(!visited[v]){
            parent[v] = u;
 
            dfs(v);
            low[u] = min(low[u], low[v]);
 
            if(low[v] > d[u]){
                ab.insert({min(u, v), max(u, v)});
            }
        }
        else if(visited[v] and v != parent[u]){
            low[u] = min(low[u], d[v]);
        }
    }
}
 
void removeBridges(){
    for(int i = 0; i < n; ++i){
        if(!visited[i]) dfs(i);
    }
}
 
void dfs(int u, int& kount, int col){
    ++kount;
    visited[u] = true;
    color[u] = col;
 
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(ab.count({min(u, v), max(u, v)}) != 0) continue;
 
        if(visited[v] and color[v] == col) found = true;
        if(!visited[v]) dfs(v, kount, col ^ 1);
    }
}
 
void calculateAns(){
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; ++i){
        found = false;
        int kount = 0;
 
        if(!visited[i]) dfs(i, kount, 0);
        if(found) ans += kount;
    }
}
 
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
 
    int tc;
    scanf("%d", &tc);
 
    for(int t = 1; t <= tc; ++t){
        reset();
        scan();
 
        removeBridges();
        calculateAns();
 
        print(t);
    }
 
    return 0;
}
