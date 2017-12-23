#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
bool g[mx][mx];
bool visited[mx];
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
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

void scan(){
    int u, v;
    while(cin >> u and u){
        while(cin >> v and v){
            g[u][v] = true;
        }
    }
}

void print(){
    int ans = 0;
    for(int u = 1; u <= n; ++u){
        if(!visited[u]) ++ans;
    }

    cout << ans;
    for(int u = 1; u <= n; ++u){
        if(!visited[u]) cout << " " << u;
    }
    cout << endl;
}

void dfs(int u){
    for(int v = 1; v <= n; ++v){
        if(g[u][v] and !visited[v]){
            visited[v] = true;
            dfs(v);
        }
    }
}

void solve(){
    int q;
    cin >> q;

    for(int i = 0; i < q; ++i){
        int u;
        cin >> u;

        clr();
        dfs(u);
        print();
    }
}

int main()
{
    //file();

    while(cin >> n and n){
        reset();
        scan();
        solve();
    }

    return 0;
}
