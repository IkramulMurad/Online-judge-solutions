#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const int mx = 105;
string table[mx];
int g[mx][mx];
int idx;
bool found, visited[mx];

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void clr(){
    found = false;
    for(int i = 0; i < mx; ++i) visited[i] = false;
}

void reset(){
    idx = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            g[i][j] = 0;
        }
    }
}

int getIdx(string s){
    int index = -1;
    for(int i = 0; i < idx; ++i){
        if(table[i] == s){
            index = i;
            break;
        }
    }
    return index;
}

void print(int u, int v, bool flag){
    if(!flag) cout << "? " << table[u] << " = ? " << table[v] << endl;
    else{
        cout << g[u][v] << " " << table[u] << " = " << g[v][u] << " " << table[v] << endl;
    }
}

void dfs(int u, int src, int des, int num, int den){
    visited[u] = true;

    if(u == des){
        found = true;
        return;
    }
    for(int v = 0; v < idx; ++v){
        if(g[u][v] and !visited[v]){
            g[src][v] = num * g[u][v];
            g[v][src] = den * g[v][u];

            int gcd = __gcd(g[src][v], g[v][src]);
            g[src][v] /= gcd;   g[v][src] /= gcd;

            //cerr << "src: " << table[src] << " v: " << table[v] << endl;
            //cerr << "num: " << g[src][v] << "den: " << g[v][src] << endl << endl;
            dfs(v, src, des, g[src][v], g[v][src]);
        }
    }
}

void solve(){
    char ch, cmd;
    string s, t;
    int m, n;

    while(true){
        cin >> cmd;
        if(cmd == '.') break;

        if(cmd == '!'){
            cin >> m >> s >> ch >> n >> t;
            int u = getIdx(s), v = getIdx(t);
            if(u == -1){
                u = idx;
                table[idx++] = s;
            }
            if(v == -1){
                v = idx;
                table[idx++] = t;
            }

            int gcd = __gcd(m, n);
            g[u][v] = m / gcd;
            g[v][u] = n / gcd;
        }
        else if(cmd == '?'){
            cin >> s >> ch >> t;
            int u = getIdx(s), v = getIdx(t);
            if(u == -1 or v == -1) print(u, v, false);
            else if(g[u][v]){
                print(u, v, true);
            }
            else{
                clr();
                dfs(u, u, v, 1, 1);
                print(u, v, found);
            }
        }
    }
}

int main()
{
    //file();

    char ch;
    while(cin >> ch){
        cin.putback(ch);

        reset();
        solve();
    }
    return 0;
}
