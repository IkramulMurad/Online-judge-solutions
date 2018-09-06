#include <bits/stdc++.h>
using namespace std;

const int mx = 100;
const int inf = 1e9;
int rg[mx][mx];
int parent[mx];
int nodes, m, w;

int in(int x){
    if(x == 1) return 1;
    return 2 * x - 2;
}

int out(int x){
    if(x == 1) return 1;
    if(x == m) return 2 * m - 2;
    return 2 * x - 1;
}

bool bfs(int s, int t){
    memset(parent, -1, sizeof(parent));
    queue <int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v = 1; v <= nodes; ++v){
            if(parent[v] == -1 and rg[u][v] > 0){
                q.push(v);
                parent[v] = u;
                if(v == t) return true;
            }
        }
    }
    return false;
}

int edmondKarp(int s, int t){
    int maxFlow = 0;
    while(bfs(s, t)){
        int minPathFlow = inf;
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            minPathFlow = min(minPathFlow, rg[u][v]);
        }

        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            rg[u][v] -= minPathFlow;
            rg[v][u] += minPathFlow;
        }

        maxFlow += minPathFlow;
    }
    return maxFlow;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        scanf("%d %d", &m, &w);

        memset(rg, 0, sizeof(rg));
        nodes = 2 * m - 2;

        //node expansion
        for(int i = 0; i < m - 2; ++i){
            int x;
            scanf("%d", &x);
            rg[in(i + 2)][out(i + 2)] = rg[out(i + 2)][in(i + 2)] = x;
        }

        //construct graph
        for(int i = 0; i < w; ++i){
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);

            rg[out(u)][in(v)] = rg[out(v)][in(u)] = c;
        }

        //print ans
        int flow = edmondKarp(1, nodes);
        printf("Case %d: %d\n", t, flow);
    }

    return 0;
}
