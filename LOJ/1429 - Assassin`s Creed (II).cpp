#include <bits/stdc++.h>
using namespace std;

const int mx = 1005;
vector <vector <int> > gg(mx), tg(mx), ng(mx), fg(mx);
int l[mx], r[mx];
bool visited[mx];

bool gm[mx][mx];
int top, stk[mx];
int sccCount, sccLabel[mx];

bool dfs(int u){
    for(int i = 0; i < fg[u].size(); ++i){
        int v = fg[u][i];
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

void dfs1(int u){
    visited[u] = true;
    for(int i = 0; i < gg[u].size(); ++i){
        int v = gg[u][i];
        if(!visited[v]) dfs1(v);
    }
    stk[top++] = u;
}

void dfs2(int u, int &sccCount){
    visited[u] = true;
    sccLabel[u] = sccCount;
    for(int i = 0; i < tg[u].size(); ++i){
        int v = tg[u][i];
        if(!visited[v]) dfs2(v, sccCount);
    }
}

void dfs3(int u){
    visited[u] = true;
    for(int i = 0; i < ng[u].size(); ++i){
        int v = ng[u][i];
        if(!visited[v]) dfs3(v);

        gm[u][v] = 1;
        for(int j = 0; j < sccCount; ++j){
            gm[u][j] |= gm[v][j];
        }
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n, m;
        scanf("%d %d", &n, &m);

        //clear
        for(int i = 0; i < mx; ++i){
            gg[i].clear();
            tg[i].clear();
            ng[i].clear();
            fg[i].clear();
        }

        //input
        for(int i = 0; i < m; ++i){
            int u, v;
            scanf("%d %d", &u, &v);

            gg[u].push_back(v);
            tg[v].push_back(u);
        }

        //topo sort
        top = 0;
        memset(visited, false, sizeof(visited));
        for(int i = 1; i <= n; ++i){
            if(!visited[i]) dfs1(i);
        }

        //scc
        sccCount = 0;
        memset(visited, false, sizeof(visited));
        while(top--){
            int u = stk[top];
            if(!visited[u]){
                dfs2(u, sccCount);
                ++sccCount;
            }
        }

        //making dag
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < gg[i].size(); ++j){
                int u = sccLabel[i], v = sccLabel[gg[i][j]];
                if(u != v) ng[u].push_back(v);
            }
        }

        //construct graph for bpm
        memset(gm, false, sizeof(gm));
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < sccCount; ++i){
            if(!visited[i]) dfs3(i);
        }

        for(int i = 0; i < sccCount; ++i){
            for(int j = 0; j < sccCount; ++j){
                if(gm[i][j]) fg[i].push_back(j);
            }
        }

        //print ans
        int ans = sccCount - bpm(sccCount);
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
