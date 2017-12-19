#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdio>
using namespace std;

const int mx = 1005;
unordered_map<string, int> table;
bool g[mx][mx], tg[mx][mx];
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
        for(int j = 0; j < mx; ++j){
            g[i][j] = tg[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        string s;
        getline(cin, s);

        table[s] = i;
    }

    for(int i = 0; i < m; ++i){
        string s, t;
        getline(cin, s); getline(cin, t);

        int u = table[s];
        int v = table[t];

        g[u][v] = true;
        tg[v][u] = true;
    }
}

void dfs(int u){
    visited[u] = true;

    for(int v = 0; v < n; ++v){
        if(g[u][v] and !visited[v]){
            dfs(v);
        }
    }
    stk[top++] = u;
}

void dfs2(int u){
    visited[u] = true;

    for(int v = 0; v < n; ++v){
        if(tg[u][v] and !visited[v]){
            dfs2(v);
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
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

void print(){
    cout << ans << endl;
}

int main()
{
    //file();

    while(cin >> n >> m and (n or m)){
        getchar();
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
