#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v, flow, cap, revIdx;

    Edge(){}
    Edge(int v, int f, int c, int r) : v(v), flow(f), cap(c), revIdx(r) {}
};

typedef vector <vector <Edge> > vve;
const int mx = 205;
const int inf = 1e9;
vve g(mx);
int start[mx];
int level[mx];

bool bfs(int s, int t){
    memset(level, -1, sizeof(level));
    level[s] = 0;

    queue <int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < g[u].size(); ++i){
            int &v = g[u][i].v;
            Edge &edge = g[u][i];

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
        int &v = g[u][i].v;
        Edge &edge = g[u][i];

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
    int maxFlow = 0;
    while(bfs(s, t)){
        memset(start, 0, sizeof(start));
        while(int flow = dfs(s, t, inf)){
            maxFlow += flow;
        }
    }
    return maxFlow;
}

void addEdge(int u, int v, int c, vve &g){
    Edge a(v, 0, c, g[v].size());
    Edge b(u, 0, 0, g[u].size());

    g[u].push_back(a);
    g[v].push_back(b);
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int m, n, total = 0;
        scanf("%d %d", &m, &n);

        for(int i = 0; i < mx; ++i){
            g[i].clear();
        }

        int x, y, source = 0, sink = m + n + 1;
        for(int i = 1; i <= m; ++i){
            scanf("%d", &x);
            total += x;
            addEdge(source, i, x, g);
        }

        for(int i = 1; i <= n; ++i){
            scanf("%d", &x);
            addEdge(i + m, sink, x, g);
        }

        for(int i = 1; i <= m; ++i){
            scanf("%d", &x);
            for(int j = 1; j <= x; ++j){
                scanf("%d", &y);
                addEdge(i, y + m, inf, g);
            }
        }

        int ans = total - dinic(source, sink);
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
