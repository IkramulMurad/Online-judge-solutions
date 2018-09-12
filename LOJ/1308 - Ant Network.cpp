#include <bits/stdc++.h>
using namespace std;
 
const int mx = 1e4 + 5;
vector<vector<int> > g(mx);
set <int> st;
bool visited[mx], ap[mx];
int parent[mx], d[mx], low[mx];
int ttime, n, m, total;
unsigned long long nums, ways;
 
void reset(){
    for(int i = 0; i < mx; ++i){
        g[i].clear();
        visited[i] = ap[i] = false;
        parent[i] = -1;
    }
    nums = ttime = total = 0;
    ways = 1;
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
    printf("Case %d: %llu %llu\n", t, nums, ways);
}
 
void dfs(int u){
    int child = 0;
    visited[u] = true;
    d[u] = low[u] = ++ttime;
 
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!visited[v]){
            parent[v] = u;
            ++child;
 
            dfs(v);
            low[u] = min(low[u], low[v]);
 
            if(parent[u] == -1 and child > 1){
                ap[u] = true;
                ++total;
            }
            else if(parent[u] != -1 and low[v] >= d[u]){
                ap[u] = true;
                ++total;
            }
        }
        else if(v != parent[u]){
            low[u] = min(low[u], d[v]);
        }
    }
}
 
void findCutPoints(){
    for(int i = 0; i < n; ++i){
        if(!visited[i]) dfs(i);
    }
}
 
void dfs(int u, int& kount){
    visited[u] = true;
    ++kount;
 
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!visited[v] and !ap[v]){
            dfs(v, kount);
        }
        else if(ap[v]){
            st.insert(v);
        }
    }
}
 
void calculateAns(){
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; ++i){
        if(!visited[i] and !ap[i]){
            int kount = 0;
            st.clear();
            dfs(i, kount);
            if(st.size() <= 1){
                ++nums;
                ways *= kount;
            }
        }
    }

    if(total == 0){
        nums = 2;
        ways = ((unsigned long long)n * (n - 1)) / 2;
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
        findCutPoints();
        calculateAns();
        print(t);
    }
 
    return 0;
}
