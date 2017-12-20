#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
using namespace std;

const int mx = 1005;
bool g[mx][mx];
bool visited[mx];
int timee;
int d[mx], low[mx], parent[mx];
map<pair<int, int>, bool> backEdge;
int n, m;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    timee = 0;
    backEdge.clear();
    for(int i = 0; i < mx; ++i){
        parent[i] = -1;
        visited[i] = false;

        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = true;
    }
}

void print(int i, int j){
    cout << i << " " << j << endl;
}

//solution is printing tree edge + back edge + bridge
void dfs(int u){
    visited[u] = true;
    d[u] = low[u] = ++timee;

    for(int v = 1; v <= n; ++v){
        if(g[u][v]){
            if(!visited[v]){
                //tree edge
                print(u, v);
                parent[v] = u;

                dfs(v);
                low[u] = min(low[u], low[v]);

                //bridge
                if(low[v] > d[u]){
                    print(v, u);
                }
            }
            //back edge
            else if(visited[v] and v != parent[u]){
                low[u] = min(low[u], d[v]);
                if(!backEdge[{u, v}] or !backEdge[{v, u}]){
                    print(u, v);
                    backEdge[{u, v}] = backEdge[{v, u}] = true;
                }
            }
        }
    }
}

void printCase(int t){
    cout << t << endl << endl;
}

void printEnd(){
    cout << "#" << endl;
}

int main()
{
    //file();

    int t = 0;
    while(cin >> n >> m and (n or m)){
        reset();
        scan();
        printCase(++t);
        dfs(1);
        printEnd();
    }

    return 0;
}
