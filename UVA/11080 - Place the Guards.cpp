#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 205;
int n, m;
int kount, kount2, ans;
bool g[mx][mx];
bool visited[mx], guard[mx];
bool impossible;

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int min(int x, int y){
    if(x < y) return x;
    return y;
}

int max(int x, int y){
    if(x > y) return x;
    return y;
}

void reset(){
    ans = 0;
    impossible = false;
    for(int i = 0; i < mx; ++i){
        guard[i] = visited[i] = false;
        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

void scan(){
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        g[u][v] = true;
        g[v][u] = true;
    }
}

void dfs(int u, bool _guard){
    visited[u] = true;
    guard[u] = _guard;

    if(_guard) ++kount;
    else ++kount2;

    for(int v = 0; v < n; ++v){
        if(g[u][v] and !visited[v]){
            dfs(v, !_guard);
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            kount = kount2 = 0;
            dfs(i, false);
            ans += max(1, min(kount, kount2));
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(g[i][j] and guard[i] == guard[j]){
                impossible = true;
            }
        }
    }
}

void print(){
    if(impossible) cout << -1 << endl;
    else cout << ans << endl;
}

int main()
{
    //fileInput();

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
