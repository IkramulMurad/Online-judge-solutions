#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int mx = 105;
bool g[mx][mx], dom[mx][mx];
bool visited[mx];
int n;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    for(int i = 0; i < mx; ++i){
        visited[i] = false;
        for(int j = 0; j < mx; ++j){
            dom[i][j] = false;
        }
    }
}

void scan(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> g[i][j];
        }
    }
}

void dfs(int u, bool visited[], int node = -1){
    visited[u] = true;
    for(int v = 0; v < n; ++v){
        if(g[u][v] and !visited[v] and v != node){
            dfs(v, visited, node);
        }
    }
}

void solve(){
    dfs(0, visited);

    for(int i = 0; i < n; ++i){
        bool vis[mx] = {false};
        if(i) dfs(0, vis, i);

        for(int j = 0; j < n; ++j){
            dom[i][j] = vis[j] ^ visited[j];
        }
    }
}

void printBorder(){
    cout << "+";
    for(int i = 1; i < 2 * n; ++i){
        cout << "-";
    }
    cout << "+" << endl;
}

void print(int t){
    cout << "Case " << t << ":" << endl;

    for(int i = 0; i < n; ++i){
        printBorder();
        for(int j = 0; j < n; ++j){
            cout << "|";
            if(dom[i][j]) cout << "Y";
            else cout << "N";
        }
        cout << "|" << endl;
    }
    printBorder();
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
