#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v, flow, cap, revIdx;

    Edge(){}
    Edge(int v, int f, int c, int r) : v(v), flow(f), cap(c), revIdx(r) {}
};

typedef vector <vector <Edge> > vve;
const int inf = 1e9;
const int mx = 2e4 + 5;
vve g(mx);
int start[mx];
int level[mx];
int n, m;
int source, sink;
int x[] = {0, -1, 1, 0};
int y[] = {-1, 0, 0, 1};

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

int in(int i, int j){
    return (i * (m * 2) + (j * 2) + 1);
}

int out(int i, int j){
    return (i * (m * 2) + (j * 2) + 2);
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

bool inBorder(int i, int j){
    return (i == 0 or j == 0 or i == n - 1 or j == m - 1);
}

void clear(){
    for(int i = 0; i < mx; ++i){
        g[i].clear();
    }
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        scanf("%d %d", &n, &m);
        source = 0; sink = 2 * n * m + 1;

        int total = 0;
        char s[n][m];
        clear();
        for(int i = 0; i < n; ++i){
            getchar();
            for(int j = 0; j < m; ++j){
                scanf("%c", &s[i][j]);

                if(s[i][j] == '*'){
                    addEdge(source, in(i, j), 1, g);
                    ++total;
                }

                if(inBorder(i, j)){
                    addEdge(out(i, j), sink, 1, g);
                }

                addEdge(in(i, j), out(i, j), 1, g);
                for(int k = 0; k < 4; ++k){
                    int ii = i + x[k];
                    int jj = j + y[k];
                    if(valid(ii, jj)){
                        addEdge(out(i, j), in(ii, jj), 1, g);
                    }
                }
            }
        }

        int flow = dinic(source, sink);
        printf("Case %d: ", t);
        if(flow == total){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }

    return 0;
}
