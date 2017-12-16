#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
char g[mx][mx];
bool visited[mx][mx];
bool flag;
int n, ans;
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void fileIO(){
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
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> g[i];
    }
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < n);
}

void dfs(int i, int j){
    visited[i][j] = true;
    if(g[i][j] == 'x') flag = true;

    for(int k = 0; k < 4; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        if(valid(ii, jj) and !visited[ii][jj] and g[ii][jj] != '.'){
            dfs(ii, jj);
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!visited[i][j] and g[i][j] != '.'){
                dfs(i, j);

                if(flag) ++ans;
                flag = false;
            }
        }
    }
}

void print(int t){
    printf("Case %d: %d\n", t, ans);
}

int main()
{
    //fileIO();

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        reset();
        scan();
        solve();
        print(t);
    }

    return 0;
}
