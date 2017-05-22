#include <bits/stdc++.h>

using namespace std;

int n, m;
const int inf = 1e9 + 5;
const int mx = 100 + 5;
int dist[mx];

typedef pair<int, int> II;
typedef vector<vector<int> > vov;
vov g(mx), cost(mx);
bitset<mx> visited;

void clr(){
    for(int i = 0; i < mx; ++i){
        g[i].clear();
        cost[i].clear();
        dist[i] = inf;
    }
    visited.reset();
}

void scan(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; ++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        g[u].push_back(v);
        g[v].push_back(u);

        cost[u].push_back(w);
        cost[v].push_back(w);
    }
}

void dijkstra(){
    priority_queue<II, vector<II>, greater<II> > pq;
    dist[1] = 0; pq.push({dist[1], 1});

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        visited[node] = 1;

        if(node == n) break;

        for(int i = 0; i < g[node].size(); ++i){
            int v = g[node][i];
            int c = cost[node][i];

            if(!visited[v] and (d + c < dist[v])){
                dist[v] = d + c;  pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        clr();
        scan();

        dijkstra();

        printf("Case %d: ", t);
        if(dist[n] < inf) printf("%d\n", dist[n]);
        else printf("Impossible\n");
    }


    return 0;
}
