#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 15;
int g[mx][mx];
bool visited[mx][mx];
int place[mx];
int n, r, c;
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    for(int i = 0; i < mx; ++i){
        place[i] = 0;
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> g[i][j];
        }
    }
}

bool valid(int i, int j){
    return (i >= 1 and j >= 1 and i <= n and j <= n);
}

bool inSquare(int i, int j){
    return (i == r or i == c or j == r or j == c);
}

void dfs(int i, int j, int& val){
    visited[i][j] = true;
    val += g[i][j];

    for(int k = 0; k < 4; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        if(valid(ii, jj) and !visited[ii][jj] and inSquare(ii, jj)){
            dfs(ii, jj, val);
        }
    }
}

void solve(){
    for(int i = 1, j = n; i <= j; ++i, --j){
        r = i; c = j;
        dfs(i, j, place[i - 1]);
    }
}

void print(int t){
    int rng = (n + 1) / 2;

    cout << "Case " << t << ":";
    for(int i = 0; i < rng; ++i){
        cout << " " << place[i];
    }
    cout << endl;
}

int main()
{
    //file();

    int t = 0;

    while(cin >> n and n){
        reset();
        scan();
        solve();
        print(++t);
    }

    return 0;
}
