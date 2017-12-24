#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
bool g[mx][mx];
int val[mx];
int n, m, ans, last;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    ans = last = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

void scan(){
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> val[i];
    }

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        g[u][v] = true;
    }
}

void dfs(int u){
    int mx = 0, tmp;
    for(int v = 0; v < n; ++v){
        if(g[u][v]){
            if(val[v] > mx){
                mx = val[v];
                tmp = v;
            }
        }
    }
    if(mx){
        ans += mx;
        last = tmp;
        dfs(tmp);
    }
}

void print(int t){
    cout << "Case " << t << ": ";
    cout << ans << " " << last << endl;
}

int main()
{
    //file();

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        reset();
        scan();
        dfs(0);
        print(t);
    }

    return 0;
}
