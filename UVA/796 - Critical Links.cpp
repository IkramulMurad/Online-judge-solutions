#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

const int mx = 105;
bool g[mx][mx];
bool visited[mx];
int d[mx], low[mx], parent[mx], timee;
int idx;
pair<int, int> links[mx];
int n;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    timee = idx = 0;
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
        char ch;
        int u, v, m;

        cin >> u;
        cin >> ch >> m >> ch;

        for(int j = 0; j < m; ++j){
            cin >> v;
            g[u][v] = g[v][u] = true;
        }
    }
}

void dfs(int u){
    visited[u] = true;
    d[u] = low[u] = ++timee;

    for(int v = 0; v < n; ++v){
        if(g[u][v]){
            if(!visited[v]){
                //tree edge
                parent[v] = u;

                dfs(v);
                low[u] = min(low[u], low[v]);

                //bridge
                if(low[v] > d[u]){
                    links[idx].first = min(u, v);
                    links[idx].second = max(u, v);
                    ++idx;
                }
            }
            //back edge
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

void print(){
    sort(links, links + idx);

    cout << idx << " critical links" << endl;
    for(int i = 0; i < idx; ++i){
        cout << links[i].first << " - " << links[i].second << endl;
    }
    cout << endl;
}

int main()
{
    //file();

    while(cin >> n){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
