#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int mx = 10005;
vector<vector<int> > g(mx);
bool visited[mx];
int n, m, l;
int ans;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    ans = 0;
    for(int i = 0; i < mx; ++i){
        visited[i] = false;
        g[i].clear();
    }
}

void scan(){
    cin >> n >> m >> l;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
    }
}

void dfs(int u){
    visited[u] = true;
    ++ans;

    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
}

void solve(){
    for(int i = 0; i < l; ++i){
        int u;
        cin >> u;

        if(!visited[u]){
            dfs(u);
        }
    }
}

void print(){
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
        print();
    }

    return 0;
}
