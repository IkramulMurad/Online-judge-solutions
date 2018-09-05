#include <bits/stdc++.h>
using namespace std;

const int mx = 105;
int gm[mx][mx];
int parent[mx];
vector <vector <int> > g(mx);

bool bfs(int s, int t){
    memset(parent, -1, sizeof(parent));
    queue <int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < g[u].size(); ++i){
            int v = g[u][i];
            if(gm[u][v] > 0 and parent[v] == -1){
                q.push(v);
                parent[v] = u;
                if(v == t) return true;
            }
        }
    }

    return false;
}

int edmondKarp(int s, int t){
    int maxflow = 0;
    while(bfs(s, t)){
        int minPathFlow = INT_MAX;
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            minPathFlow = min(minPathFlow, gm[u][v]);
        }

        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            gm[u][v] -= minPathFlow;
            gm[v][u] += minPathFlow;
        }

        maxflow += minPathFlow;
    }
    return maxflow;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    cin >> tc;

    for(int ti = 1; ti <= tc; ++ti){
        int n, s, t, m;
        cin >> n >> s >> t >> m;

        //input graph
        memset(gm, 0, sizeof(gm));
        for(int i = 0; i < m; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            gm[u][v] += w;
            gm[v][u] += w;
        }

        //construct graph
        g.clear();
        for(int u = 1; u <= n; ++u){
            for(int v = u + 1; v <= n; ++v){
                if(gm[u][v]){
                    g[u].push_back(v);
                    g[v].push_back(u);
                }
            }
        }

        //print answer
        int ans = edmondKarp(s, t);
        printf("Case %d: %d\n", ti, ans);
    }

    return 0;
}
