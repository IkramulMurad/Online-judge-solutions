#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int mx = 26;
bool g[mx][mx];
bool visited[mx];
int stk[mx], top;
vector<vector<int> > scc(mx);
bool taken[mx], appear[mx];
int n, total;

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
    top = total = 0;

    for(int i = 0; i < mx; ++i){
        scc[i].clear();
        taken[i] = appear[i] = false;
        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        int a[6];
        char line[15];
        gets(line);

        for(int i = 0, j = 0; line[i]; ++i){
            if(line[i] != ' '){
                a[j++] = line[i] - 'A';
                appear[a[j - 1]] = true;
            }
        }

        for(int i = 0; i < 5; ++i){
            int u = a[5], v = a[i];
            if(u != v){
                g[u][v] = true;
            }
        }
    }
}

void dfs(int u){
    visited[u] = true;

    for(int v = 0; v < mx; ++v){
        if(g[u][v] and !visited[v]){
            dfs(v);
        }
    }

    stk[top++] = u;
}

void dfs2(int u){
    visited[u] = true;
    scc[total].push_back(u);

    for(int v = 0; v < mx; ++v){
        if(g[v][u] and !visited[v]){
            dfs2(v);
        }
    }
}

void solve(){
    for(int i = 0; i < mx; ++i){
        if(appear[i] and !visited[i]){
            dfs(i);
        }
    }

    clr();
    for(int i = top - 1; i >= 0; --i){
        int u = stk[i];
        if(!visited[u]){
            dfs2(u);
            ++total;
        }
    }
}

int pick(){
    int mn = mx;
    int idx = -1;

    for(int i = 0; i < total; ++i){
        if(!taken[i] and mn > scc[i].front()){
            mn = scc[i].front();
            idx = i;
        }
    }

    taken[idx] = true;

    return idx;
}

void print(int t){
    if(t) cout << endl;

    //sort all the scc's
    for(int i = 0; i < total; ++i){
        sort(scc[i].begin(), scc[i].end());
    }

    //choose scc by least element
    for(int i = 0; i < total; ++i){
        int idx = pick();
        for(int j = 0; j < scc[idx].size(); ++j){
            char ch = 'A' + scc[idx][j];
            if(j) cout << " ";
            cout << ch;
        }
        cout << endl;
    }
}

int main()
{
    //file();

    int t = 0;
    while(cin >> n and n){
        getchar();
        reset();
        scan();
        solve();
        print(t++);
    }

    return 0;
}
