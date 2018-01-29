#include <iostream>
using namespace std;

const int mx = 1005;
bool g[mx][mx], visited[mx][mx];
int n, m, total, largest;
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void reset(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

void scan(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> g[i][j];
        }
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

        if(valid(ii, jj) and g[ii][jj] and !visited[ii][jj]){
            dfs(ii, jj, kount);
        }
    }
}

void solve(){
    total = largest = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(g[i][j] and !visited[i][j]){
                int kount = 0;
                dfs(i, j, kount);

                largest = max(largest, kount);
                ++total;
            }
        }
    }
}

void print(){
    cout << total << " " << largest << endl;
}

int main()
{
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
