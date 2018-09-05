#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int mx = 205;
int parent[mx];
int gm[mx][mx];
int barishal, dhaka;

inline int in(int x){
    return x * 2 - 1;
}

inline int out(int x){
    return x * 2;
}

bool bfs(int s, int t){
    memset(parent, -1, sizeof(parent));
    queue <int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v = 0; v <= dhaka; ++v){
            if(parent[v] == -1 and gm[u][v] > 0){
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
            minPathFlow = min(minPathFlow, gm[u][v]);
        }

        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            gm[u][v] -= minPathFlow;
            gm[v][u] += minPathFlow;
        }

        maxFlow += minPathFlow;
    }
    return maxFlow;
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tc;
    scanf("%d", &tc);

    for(int tt = 1; tt <= tc; ++tt){
        //input graph
        int n;
        scanf("%d", &n);

        barishal = 0, dhaka = 2 * n + 1;
        memset(gm, 0, sizeof(gm));

        for(int i = 1; i <= n; ++i){
            int w;
            scanf("%d", &w);
            gm[in(i)][out(i)] = w;
        }

        int m;
        scanf("%d", &m);
  
        for(int i = 0; i < m; ++i){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            gm[out(u)][in(v)] = w;
        }

        int s, t, x;
        scanf("%d %d", &s, &t);

        for(int i = 0; i < s; ++i){
            scanf("%d", &x);
            gm[barishal][in(x)] = inf;
        }

        for(int i = 0; i < t; ++i){
            scanf("%d", &x);
            gm[out(x)][dhaka] = inf;
        }

        //print answer
        int ans = edmondKarp(barishal, dhaka);
        printf("Case %d: %d\n", tt, ans);
    }

    return 0;
}
