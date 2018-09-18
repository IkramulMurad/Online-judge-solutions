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

    for(int i = 0; i < n; ++i){
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
        int n;
        scanf("%d", &n);

        int b[n], e[n], xa[n], xb[n], xc[n], xd[n];
        for(int i = 0; i < n; ++i){
            char garbage;
            int hour, minute;
            cin >> hour >> garbage >> minute >> xa[i] >> xb[i] >> xc[i] >> xd[i];
            
            b[i] = hour * 60 + minute;
            e[i] = b[i] + abs(xa[i] - xc[i]) + abs(xb[i] - xd[i]);
        }

        for(int i = 0; i < mx; ++i) g[i].clear();

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(e[i] + abs(xa[j] - xc[i]) + abs(xb[j] - xd[i]) < b[j]){
                    g[i].push_back(j);
                }
            }
        }

        int ans = n - bpm(n);
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
