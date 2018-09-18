#include <bits/stdc++.h>
using namespace std;

const int mx = 405;
vector <vector <int> > g(mx);
int l[mx], r[mx];
bool visited[mx];

int color[mx];
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

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
        if(color[i] and dfs(i)) ++total;
    }
    return total;
}

bool valid(int i, int j, int n, int m){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void dfs(int u, bool clr){
    visited[u] = true;
    color[u] = clr;

    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!visited[v]) dfs(v, clr ^ 1);
    }
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n, m;
        scanf("%d %d", &n, &m);

        string s[n];
        for(int i = 0; i < n; ++i) cin >> s[i];

        int a[n][m];
        int idx = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(s[i][j] == '*'){
                    a[i][j] = idx++;
                }
            }
        }

        for(int i = 0; i < mx; ++i) g[i].clear();

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(s[i][j] == '*'){
                    for(int k = 0; k < 4; ++k){
                        int ii = i + x[k], jj = j + y[k];
                        if(valid(ii, jj, n, m) and s[ii][jj] == '*'){
                            int u = a[i][j], v = a[ii][jj];
                            g[u].push_back(v);
                        }
                    }
                }
            }
        }

        memset(visited, false, sizeof(visited));
        memset(color, 0, sizeof(color));
        for(int i = 0; i < idx; ++i){
            if(!visited[i]) dfs(i, 0);
        }

        int ans = idx - bpm(idx);
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
