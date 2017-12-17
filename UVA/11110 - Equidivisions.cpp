#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
int g[mx][mx];
bool visited[mx][mx];
bool wrong;
int n;
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    wrong = false;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
            g[i][j] = 0;
        }
    }
}

void scan(){
    for(int i = 1; i < n; ++i){
        int u, v;
        char ch;

        while(true){
            scanf("%d %d%c", &u, &v, &ch);
            g[u][v] = i;
            if(ch == '\n' or ch == '\0') break;
        }
    }
}

bool valid(int i, int j){
    return (i >= 1 and j >= 1 and i <= n and j <= n);
}

void dfs(int i, int j, int num, int& kount){
    visited[i][j] = true;
    ++kount;

    for(int k = 0; k < 4; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        if(valid(ii, jj) and !visited[ii][jj] and g[ii][jj] == num){
            dfs(ii, jj, num, kount);
        }
    }
}

void solve(){
    for(int i = 1; i <= n and !wrong; ++i){
        for(int j = 1; j <= n and !wrong; ++j){
            if(!visited[i][j]){
                int kount = 0;
                dfs(i, j, g[i][j], kount);
                if(kount != n) wrong = true;
            }
        }
    }
}

void print(){
    if(wrong) cout << "wrong" << endl;
    else cout << "good" << endl;
}

int main()
{
    //file();

    while(cin >> n and n){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
