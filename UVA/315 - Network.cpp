#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
bool g[mx][mx];
bool visited[mx];
int timee;
int d[mx], low[mx], parent[mx];
bool articulation[mx];
int n;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    timee = 0;
    for(int i = 0; i < mx; ++i){
        visited[i] = articulation[i] = false;
        d[i] = low[i] = 0;
        parent[i] = -1;

        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

bool intFromLine(int& x){
    bool flag = true;
    char ch;
    while(cin.get(ch)){
        if(ch == '\n'){
            flag = false;
            break;
        }
        if(ch >= '0' and ch <= '9'){
            cin.putback(ch);
            cin >> x;
            break;
        }
    }
    return flag;
}

void scan(){
    int u, v;

    while(intFromLine(u) and u){
        while(intFromLine(v)){
            g[u][v] = g[v][u] = true;
        }
    }
}

void dfs(int u){
    int child = 0;
    visited[u] = true;
    d[u] = low[u] = ++timee;

    for(int v = 1; v <= n; ++v){
        if(g[u][v]){
            if(!visited[v]){
                ++child;
                parent[v] = u;

                dfs(v);

                low[u] = min(low[u], low[v]); //tree edge

                if(parent[u] == -1 and child > 1){
                    articulation[u] = true;
                }
                if(parent[u] != -1 and low[v] >= d[u]){
                    articulation[u] = true;
                }
            }
            //back edge
            else if(visited[v] and v != parent[u]){
                low[u] = min(low[u], d[v]);
            }
        }
    }
}

void print(){
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(articulation[i]) ++ans;
    }
    cout << ans << endl;
}

int main()
{
    //file();

    while(cin >> n and n){
        getchar();
        reset();
        scan();
        dfs(1);
        print();
    }

    return 0;
}
