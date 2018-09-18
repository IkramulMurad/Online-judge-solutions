#include <bits/stdc++.h>
using namespace std;

const int mx = 1005;
vector <vector <int> > g(mx);
int l[mx], r[mx];
bool visited[mx];

bool dfs(int u){
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!visited[v]){
            visited[v] = true;
            if(l[v] == -1 or dfs(l[v])){
                l[v] = u;
                r[u] = v;
                return true;
            }
        }
    }
    return false;
}

int bpm(int n){
    int total = 0;
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));

    for(int i = 1; i <= n; ++i){
        memset(visited, false, sizeof(visited));
        if(dfs(i)) ++total;
    }
    return total;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i = 0; i < mx; ++i) g[i].clear();

        for(int i = 0; i < m; ++i){
            int u, v;
            scanf("%d %d", &u, &v);

            g[u].push_back(v);
        }

        int ans = n - bpm(n);
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
