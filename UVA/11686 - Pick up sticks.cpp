#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int mx = 1e6 + 5;
vector<vector<int> > g(mx);
int indeg[mx];
bool visited[mx];
bool impossible;
int n, m;
int stk[mx], idx;

void fileIO(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    impossible = true;
    idx = 0;
    for(int i = 0; i < mx; ++i){
        g[i].clear();
        visited[i] = false;
        indeg[i] = 0;
    }
}

void scan(){
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        ++indeg[v];
    }
}

void dfs(int u){
    visited[u] = true;

    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }

    stk[idx++] = u;
}

void solve(){
    for(int i = 1; i <= n; ++i){
        if(indeg[i] == 0){
            impossible = false;
            dfs(i);
        }
    }
}

void print(){
    if(impossible){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(int i = idx - 1; i >= 0; --i){
        cout << stk[i] << endl;
    }

}

int main()
{
    //fileIO();

    while(cin >> n >> m and (n or m)){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
