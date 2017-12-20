#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int mx = 105;
unordered_map<string, int> table;
unordered_map<int, string> rtable;
bool g[mx][mx];
bool visited[mx];
int d[mx], low[mx], parent[mx], etime;
set<string> ans;
int n, m;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    etime = 0;
    table.clear();
    rtable.clear();
    ans.clear();

    for(int i = 0; i < mx; ++i){
        visited[i] = false;
        parent[i] = -1;

        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        string spot;
        cin >> spot;

        table[spot] = i;
        rtable[i] = spot;
    }

    cin >> m;
    for(int i = 0; i < m; ++i){
        string s, t;
        cin >> s >> t;

        int u = table[s], v = table[t];
        g[u][v] = g[v][u] = true;
    }
}

bool root(int u){
    return parent[u] == -1;
}

void dfs(int u){
    int child = 0;
    visited[u] = true;
    d[u] = low[u] = ++etime;

    for(int v = 0; v < n; ++v){
        if(g[u][v]){
            if(!visited[v]){
                ++child;
                parent[v] = u;

                dfs(v);
                low[u] = min(low[u], low[v]);

                if(root(u) and child > 1){
                    ans.insert(rtable[u]);
                }
                if(!root(u) and low[v] >= d[u]){
                    ans.insert(rtable[u]);
                }
            }
            else if(visited[v] and v != parent[u]){
                low[u] = min(low[u], d[v]);
            }
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            dfs(i);
        }
    }
}

void print(int t){
    if(t > 1) cout << endl;
    cout << "City map #" << t << ": " << ans.size() << " camera(s) found" << endl;

    for(auto spot : ans){
        cout << spot << endl;
    }
}

int main()
{
    //file();

    int t = 0;
    while(cin >> n and n){
        reset();
        scan();
        solve();
        print(++t);
    }

    return 0;
}
