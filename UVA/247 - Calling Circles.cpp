#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 30;
char table[mx][mx];
int size;
bool g[mx][mx], tg[mx][mx];
bool visited[mx];
int stk[mx], top;
int n, m;

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
    size = top = 0;

    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            g[i][j] = tg[i][j] = false;
        }
    }
}

int len(char s[]){
    int i;
    for(i = 0; s[i]; ++i){}
    return i;
}

bool match(char s[], char t[]){
    int lens = len(s);
    if(lens != len(t)) return false;

    for(int i = 0; i < lens; ++i){
        if(s[i] != t[i]) return false;
    }
    return true;
}

int getIndex(char s[]){
    int idx = -1;

    for(int i = 0; i < size; ++i){
        if(match(s, table[i])){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        int lens = len(s);
        for(int i = 0; i < lens; ++i){
            table[size][i] = s[i];
        }
        table[size][lens] = '\0';

        idx = size;
        ++size;
    }

    return idx;
}

void scan(){
    for(int i = 0; i < m; ++i){
        char s[mx], t[mx];
        cin >> s >> t;

        int u = getIndex(s);
        int v = getIndex(t);

        g[u][v] = true;
        tg[v][u] = true;
    }
}

void print(int u, int kount){
    if(kount) cout << ", ";
    cout << table[u];
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

void dfs2(int u, int& kount){
    visited[u] = true;
    print(u, kount);
    ++kount;

    for(int v = 0; v < n; ++v){
        if(tg[u][v] and !visited[v]){
            dfs2(v, kount);
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
            int kount = 0;
            dfs2(u, kount);
            cout << endl;
        }
    }
}

void printCase(int t){
    if(t > 1) cout << endl;
    cout << "Calling circles for data set " << t << ":" << endl;
}

int main()
{
    //file();

    int t = 0;
    while(cin >> n >> m and (n or m)){
        reset();
        scan();
        printCase(++t);
        solve();
    }

    return 0;
}
