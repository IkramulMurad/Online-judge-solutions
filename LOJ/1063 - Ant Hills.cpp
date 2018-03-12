#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
 
const int mx = 1e4 + 5;
const int inf = 1e9;
vector<vector<int> > g(mx);
bool visited[mx], ap[mx];
int d[mx], low[mx], parent[mx];
int n, m, timee;
 
void reset(){
    for(int i = 0; i < mx; ++i){
        ap[i] = visited[i] = false;
        g[i].clear();
 
        timee = 0;
        parent[i] = -1;
        d[i] = low[i] = inf;
    }
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
    int ans = 0;
    for(int i = 1; i <= n; ++i) if(ap[i]) ++ans;
    printf("Case %d: %d\n", t, ans);
}
 
void dfs(int u){
    int child = 0;
    visited[u] = true;
    d[u] = low[u] = ++timee;
 
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
 
        if(!visited[v]){
            ++child;
            parent[v] = u;
 
            dfs(v);
            low[u] = min(low[u], low[v]);
 
            if(parent[u] == -1 and child > 1) ap[u] = true;
            if(parent[u] != -1 and low[v] >= d[u]) ap[u] = true;
        }
        else if(visited[v] and v != parent[u]){
            low[u] = min(low[u], d[v]);
        }
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
        dfs(1);
        print(t);
    }
 
    return 0;
}
