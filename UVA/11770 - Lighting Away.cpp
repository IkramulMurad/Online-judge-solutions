#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int mx = 1e4 + 5;
vector<vector<int> > g(mx);
bool visited[mx];
int stk[mx], top;
int n, m, ans;

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
    top = ans = 0;
    for(int i = 0; i < mx; ++i){
        g[i].clear();
    }
}

void scan(){
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
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

void dfs2(int u){
    visited[u] = true;

    for(auto v : g[u]){
        if(!visited[v]){
            dfs2(v);
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
            ++ans;
            dfs2(u);
        }
    }
}

void print(int t){
    cout << "Case " << t << ": " << ans << endl;
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
