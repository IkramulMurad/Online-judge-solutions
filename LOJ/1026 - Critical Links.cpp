#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
 
const int mx = 1e4 + 5;
const int inf = 1e9;
vector<vector<int> > g(mx);
pair<int, int> links[mx];
bool visited[mx];
int parent[mx], low[mx], d[mx];
int n, timee, idx;
 
void reset(){
    for(int i = 0; i < mx; ++i){
        timee = idx = 0;
        parent[i] = -1;
        low[i] = d[i] = inf;
 
        visited[i] = false;
        g[i].clear();
    }
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
                links[idx].first = min(u, v);
                links[idx].second = max(u, v);
                ++idx;
            }
        }
        else if(visited[v] and v != parent[u]){
            low[u] = min(low[u], d[v]);
        }
    }
}
 
void solve(){
    for(int i = 0; i < n; ++i){
        if(!visited[i]) dfs(i);
    }
}
 
void scan(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        int u, m;
        scanf("%d %*c %d %*c", &u, &m);
 
        for(int j = 0; j < m; ++j){
            int v;
            cin >> v;
 
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
}
 
void print(int t){
    printf("Case %d:\n", t);
    printf("%d critical links\n", idx);
 
    sort(links, links + idx);
    for(int i = 0; i < idx; ++i){
        printf("%d - %d\n", links[i].first, links[i].second);
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
        solve();
        print(t);
    }
 
    return 0;
}
