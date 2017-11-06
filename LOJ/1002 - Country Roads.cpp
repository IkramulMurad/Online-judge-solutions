#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> II;

const int mx = 505;
vector<vector<int> > g(mx), c(mx);
vector<II> dist;
bitset<mx> visited;

void clr(){
    for(int i = 0; i < mx; ++i) g[i].clear(), c[i].clear();
    dist.clear();
    visited.reset();
}

void prims(int source){
    priority_queue<II, vector<II>, greater<II> > pq;
    pq.push(make_pair(0, source));

    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(!visited[node]){
            visited[node] = 1;
            dist.push_back(make_pair(node, cost));
        }

        vector<int> v = g[node];
        vector<int> w = c[node];

        for(int i = 0; i < v.size(); ++i){
            //max of prev cost and new cost
            int wi = max(w[i], cost);
            if(!visited[v[i]]){
                pq.push(make_pair(wi, v[i]));
            }
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n, m;
        scanf("%d %d", &n, &m);

        clr();

        for(int i = 0; i < m; ++i){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            g[u].push_back(v);
            g[v].push_back(u);

            c[u].push_back(w);
            c[v].push_back(w);
        }

        int source;
        scanf("%d", &source);

        prims(source);

        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                dist.push_back(make_pair(i, -1));
            }
        }

        sort(dist.begin(), dist.end());

        printf("Case %d:\n", t);
        for(int i = 0; i < dist.size(); ++i){
            if(dist[i].second == -1){
                printf("Impossible\n");
            }
            else{
                printf("%d\n", dist[i].second);
            }
        }

    }
    return 0;
}
