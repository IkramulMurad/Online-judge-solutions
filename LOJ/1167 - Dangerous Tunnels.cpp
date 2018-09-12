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
int source, sink;
int n, m, k, mxDanger;
int graph[mx][mx];
vector <int> st;

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

void addEdge(int u, int v, int c, vve &g){
    Edge a(v, 0, c, g[v].size());
    Edge b(u, 0, 0, g[u].size());

    g[u].push_back(a);
    g[v].push_back(b);
}

int in(int i){
    if(i == 0) return i;
    return (2 * i - 1);
}

int out(int i){
    if(i == n + 1) return (2 * i - 1);
    return 2 * i;
}

void makeGraph(int mid){
    for(int i = 0; i < mx; ++i){
        g[i].clear();
    }

    for(int i = 1; i <= n; ++i){
        addEdge(in(i), out(i), 1, g);
    }

    int total = lower_bound(st.begin(), st.end(), mid + 1) - st.begin();

    for(int i = 0; i <= n + 1; ++i){
        for(int j = i + 1; j <= n + 1; ++j){
            if(i == 0 and j == n + 1){
                addEdge(out(i), in(j), total, g);
            }
            else if(graph[i][j] and graph[i][j] <= mid){
                addEdge(out(i), in(j), inf, g);
            }
        }
    }
}

int binSearch(){
    int lo = 0, hi = mxDanger, ret = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        makeGraph(mid);
        int flow = dinic(source, sink);
        //cerr << "lo: " << lo << ", hi: " << hi << endl;
        //cerr << "mid: " << mid << ", flow: " << flow << endl;
        if(flow >= k){
            hi = mid - 1;
            ret = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return ret;
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        scanf("%d %d", &n, &m);

        mxDanger = 0;
        st.clear();
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i < m; ++i){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            mxDanger = max(mxDanger, w);
            if(min(u, v) == 0 and max(u, v) == n + 1){
                st.push_back(w);
            }
            else if((min(u, v) == 0 or max(u, v) == n + 1) and graph[min(u, v)][max(u, v)]){
                graph[min(u, v)][max(u, v)] = min(graph[min(u, v)][max(u, v)], w);
            }
            else graph[min(u, v)][max(u, v)] = w;
            
        }
        sort(st.begin(), st.end());

        scanf("%d", &k);
        source = 0; sink = 2 * n + 1;
        int ans = binSearch();
        
        printf("Case %d: ", t);
        if(ans == -1) printf("no solution\n");
        else printf("%d\n", ans);
    }

    return 0;
}
