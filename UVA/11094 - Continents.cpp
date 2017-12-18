#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 25;
char g[mx][mx];
bool visited[mx][mx];
int m, n, r, c, ans;
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
    for(int i = 0; i < m; ++i){
        cin >> g[i];
    }
    cin >> r >> c;
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < m and j < n);
}

void dfs(int i, int j, int& kount, char land){
    visited[i][j] = true;
    ++kount;

    for(int k = 0; k < 4; ++k){
        int ii = i + x[k];
        int jj = (j + y[k] + n) % n;

        if(valid(ii, jj) and !visited[ii][jj] and g[ii][jj] == land){
            dfs(ii, jj, kount, land);
        }
    }
}

void solve(){
    int kount = 0;
    char land = g[r][c];

    dfs(r, c, kount, land);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(g[i][j] == land and !visited[i][j]){
                kount = 0;
                dfs(i, j, kount, g[i][j]);
                ans = ans > kount ? ans : kount;
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
