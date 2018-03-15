#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> II;
const int mx = 1e4 + 5;
const int inf = 1e9;
vector<vector<int> > g(mx);
bool visited[mx];
int parent[mx], d[mx], low[mx], sccBoss[mx], deg[mx];
set<II> ab;
int timee, scc, n, m;
 
void reset(){
    for(int i = 0; i < mx; ++i){
        g[i].clear();
        visited[i] = false;
 
        d[i] = low[i] = inf;
        parent[i] = -1;
        sccBoss[i] = i;
        deg[i] = 0;
    }
    timee = scc = 0;
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
 
void print(int t, int ans){
    printf("Case %d: %d\n", t, ans);
}
 
void dfs(int u){
    visited[u] = true;
    d[u] = low[u] = ++timee;
 
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
 
void dfs(int u, int boss){
    visited[u] = true;
    sccBoss[u] = boss;
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!visited[v] and ab.count({min(u, v), max(u, v)}) == 0) dfs(v, boss);
    }
}
 
void findConnectedCompos(){
    memset(visited, false, sizeof(visited));
    for(int u = 0; u < n; ++u){
        if(!visited[u]){
            ++scc;
            dfs(u, u);
        }
    }
}
 
int singleBridgeCompos(){
    int kount = 0;
    for(set<II>::iterator it = ab.begin(); it != ab.end(); ++it){
        int u = it->first, v = it->second;
        ++deg[sccBoss[u]];
        ++deg[sccBoss[v]];
    }
 
    for(int i = 0; i < n; ++i){
        if(deg[i] == 1) ++kount;
    }
 
    return kount;
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
 
        dfs(0);
        findConnectedCompos();
        int ans = (singleBridgeCompos() + 1) / 2;
 
        print(t, ans);
    }
 
    return 0;
