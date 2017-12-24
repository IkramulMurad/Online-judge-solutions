#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int mx = 5e4 + 5;
vector<vector<int> > g(mx), tg(mx);
bool visited[mx];
int stk[mx], top;
int sccBoss[mx], sccCount[mx];
int n;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void clr(){
    for(int i = 0; i < mx; ++i){
        visited[i] = false;
    }
}

void reset(){
    clr();
    top = 0;
    for(int i = 0; i < mx; ++i){
        sccBoss[i] = mx;
        sccCount[i] = 0;
        g[i].clear(); tg[i].clear();
    }
}

void scan(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        tg[v].push_back(u);
    }
}

void dfs(int u){
    visited[u] = true;

    for(auto v : g[u]){
        if(!visited[v]){
            dfs(v);
        }
    }

    stk[top++] = u;
}

void dfs2(int u, int& kount, int& mn){
    ++kount;
    visited[u] = true;
    mn = min(mn, u);

    for(auto v : tg[u]){
        if(!visited[v]){
            dfs2(v, kount, mn);
        }
    }

    sccBoss[u] = mn;
}

void dfs3(int u){
    visited[u] = true;

    for(auto v : g[u]){
        if(sccBoss[u] != sccBoss[v]){
            if(!visited[v]) dfs3(v);
            sccCount[sccBoss[u]] += sccCount[sccBoss[v]];
        }
    }
}

void solve(){
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            dfs(i);
        }
    }

    clr();
    for(int i = top - 1; i >= 0; --i){
        int u = stk[i];
        if(!visited[u]){
            int kount = 0, mn = mx;

            dfs2(u, kount, mn);
            sccCount[sccBoss[u]] = kount;
        }
    }

    clr();
    for(int i = top - 1; i >= 0; --i){
        int u = stk[i];
        if(!visited[u] and sccBoss[u] == u){
            dfs3(u);
        }
    }
}

void print(int t){
    int ans = 0, hi = 0;
    cout << "Case " << t << ": ";

    for(int i = 1; i <= n; ++i){
        //cerr << i << ": " << sccBoss[i] << " " << sccCount[sccBoss[i]] << endl;
        if(sccCount[sccBoss[i]] > hi){
            hi = sccCount[sccBoss[i]];
            ans = sccBoss[i];
        }
    }
    cout << ans << endl;
}

int main()
{
    //file();

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        reset();
        scan();
        solve();
        print(t);
    }

    return 0;
}
