#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 55;
int ans, n, m;
char g[mx][mx];
bool visited[mx][mx];
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    ans = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        cin >> g[i];
    }
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

bool getDraft(int i, int j){
    for(int k = 0; k < 4; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        if(valid(ii, jj) and g[ii][jj] == 'T'){
            return true;
        }
    }
    return false;
}

void dfs(int i, int j){
    if(g[i][j] == 'G') ++ans;
    visited[i][j] = true;

    if(getDraft(i, j)) return;
    for(int k = 0; k < 4; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        if(valid(ii, jj) and !visited[ii][jj] and g[ii][jj] != '#'){
            dfs(ii, jj);
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(g[i][j] == 'P'){
                dfs(i, j);
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

    while(cin >> m >> n){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
