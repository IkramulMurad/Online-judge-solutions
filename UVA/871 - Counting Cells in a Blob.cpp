#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 30;
char g[mx][mx];
bool visited[mx][mx];
int n, m, ans, kount;
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int len(char s[]){
    int i;
    for(i = 0; s[i]; ++i){}
    return i;
}

int max(int x, int y){
    if(x > y) return x;
    return y;
}

void reset(){
    ans = 0;
    n = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

void scan(){
    while(gets(g[n])){
        if(g[n][0] == '\0') break;
        m = len(g[n]);
        ++n;
    }
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void dfs(int i, int j, int& kount){
    visited[i][j] = true;
    ++kount;

    for(int k = 0; k < 8; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        if(valid(ii, jj) and !visited[ii][jj] and g[ii][jj] == '1'){
            dfs(ii, jj, kount);
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(g[i][j] == '1' and !visited[i][j]){
                kount = 0;
                dfs(i, j, kount);
                ans = max(ans, kount);
            }
        }
    }
}

void print(){
    cout << ans << endl;
}

int main()
{
    //file();

    int tc;
    scanf("%d ", &tc);

    for(int t = 0; t < tc; ++t){
        if(t) cout << endl;
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
