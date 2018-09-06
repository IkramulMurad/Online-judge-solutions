#include <bits/stdc++.h>
using namespace std;

const int mx = 60;
const int inf = 1e9;
int rg[mx][mx];
int parent[mx];
int nodes;
map <string, int> mp;
string str[] = {"XS", "S", "M", "L", "XL", "XXL"};

bool bfs(int s, int t){
    memset(parent, -1, sizeof(parent));
    queue <int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v = 0; v < nodes; ++v){
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

void pre(){
    for(int i = 0; i < 6; ++i){
        mp[str[i]] = i + 1;
    }
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    pre();
    for(int t = 1; t <= tc; ++t){
        int n, m;
        scanf("%d %d", &n, &m);

        nodes = m + 8;
        memset(rg, 0, sizeof(rg));

        //source to t-shirt size
        for(int i = 1; i <= 6; ++i){
            rg[0][i] = rg[i][0] = n;
        }

        //contestant to sink
        for(int i = 0; i < m; ++i){
            rg[i + 7][m + 7] = rg[m + 7][i + 7] = 1;
        }

        //t-shirt size to contestant
        for(int i = 0; i < m; ++i){
            string s1, s2;
            cin >> s1 >> s2;

            int x = mp[s1], y = mp[s2];
            rg[x][i + 7] = rg[i + 7][x] = 1;
            rg[y][i + 7] = rg[i + 7][y] = 1;
        }

        //print answer
        int flow = edmondKarp(0, m + 7);
        if(flow == m) printf("Case %d: YES\n", t);
        else printf("Case %d: NO\n", t);
    }

    return 0;
}
