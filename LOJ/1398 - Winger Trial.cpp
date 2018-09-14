#include <bits/stdc++.h>
using namespace std;
 
struct Edge{
    int v, flow, cap, revIdx;
   
    Edge(){}
    Edge(int v, int flow, int cap, int revIdx) : v(v), flow(flow), cap(cap), revIdx(revIdx) {}
};
 
typedef vector <vector <Edge> > vve;
const int inf = 1e9;
const int mx = 205;
vve g(mx);
int level[mx];
int start[mx];
 
void addEdge(int u, int v, int c, vve &g){
    Edge a(v, 0, c, g[v].size());
    Edge b(u, 0, 0, g[u].size());
 
    g[u].push_back(a);
    g[v].push_back(b);
}
 
bool bfs(int s, int t){
    memset(level, -1, sizeof(level));
    level[s] = 0;
 
    queue <int> q;
    q.push(s);
 
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < g[u].size(); ++i){
            Edge &edge = g[u][i];
            int &v = edge.v;
            if(level[v] == -1 and edge.flow < edge.cap){
                q.push(v);
                level[v] = level[u] + 1;
                if(v == t) return true;
            }
        }
    }
    return false;
}
 
int dfs(int u, int t, int prevFlow){
    if(u == t) return prevFlow;
 
    for(int &i = start[u]; i < g[u].size(); ++i){
        Edge &edge = g[u][i];
        int &v = edge.v;
 
        if(level[v] == level[u] + 1 and edge.flow < edge.cap){
            int minFlowTillNow = min(prevFlow, edge.cap - edge.flow);
            int minPathFlow = dfs(v, t, minFlowTillNow);
            if(minPathFlow > 0){
                edge.flow += minPathFlow;
                g[v][edge.revIdx].flow -= minPathFlow;
                return minPathFlow;
            }
        }
    }
    return 0;
}
 
int dinic(int s, int t){
    if(s == t) return 0;
    int maxFlow = 0;
    while(bfs(s, t)){
        memset(start, 0, sizeof(start));
        while(int flow = dfs(s, t, inf)){
            maxFlow += flow;
        }
    }
    return maxFlow;
}

int in(int i){
    return 2 * i - 1;
}

int out(int i){
    return 2 * i;
}
 
int main(){
    //freopen("in.txt", "r", stdin);
 
    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int l, w, n, d, source, sink;
        scanf("%d %d %d %d", &l, &w, &n, &d);

        source = 0; sink = 2 * n + 1;
        int x[n + 1], y[n + 1];
        for(int i = 1; i <= n; ++i){
            scanf("%d %d", &x[i], &y[i]);
        }

        for(int i = 0; i < mx; ++i){
            g[i].clear();
        }
        for(int i = 1; i <= n; ++i){
            addEdge(in(i), out(i), 1, g);
            if(w - y[i] <= d){
                addEdge(source, in(i), 1, g);
            }
            if(y[i] <= d){
                addEdge(out(i), sink, 1, g);
            }
        }

        for(int i = 1; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j){
                int xx = abs(x[i] - x[j]);
                int yy = abs(y[i] - y[j]);
                if((xx * xx) + (yy * yy) <= 4 * d * d){
                    addEdge(out(i), in(j), 1, g);
                    addEdge(out(j), in(i), 1, g);
                }
            }
        }

        int ans = dinic(source, sink);
        printf("Case %d: %d\n", t, ans);
    }
 
    return 0;
}
