#include <iostream>
#include <cstdio>
using namespace std;

const int nx = 50;
const int mx = 100;
char g[nx][mx];
bool visited[nx][mx];
int n, m[nx], mm;
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    for(int i = 0; i < nx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

bool valid(int i, int j){
    if(i >= 0 and j >= 0 and i < n and j < mm) return true;
    return false;
}

bool hasAdjCon(int i, int j){
    for(int k = 0; k < 4; ++k){
        int newI = i + x[k];
        int newJ = j + y[k];
        if(valid(newI, newJ) and g[newI][newJ] != ' ' and g[newI][newJ] != '#'){
            return true;
        }
    }
    return false;
}

void dfs(int i, int j){
    if(hasAdjCon(i, j)){
        g[i][j] = '#';
    }
    visited[i][j] = true;

    for(int k = 0; k < 4; ++k){
        int newI = i + x[k];
        int newJ = j + y[k];
        if(valid(newI, newJ) and g[newI][newJ] == ' ' and !visited[newI][newJ]){
            dfs(newI, newJ);
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        for(int j = m[i]; j < mm; ++j){
            g[i][j] = ' ';
        }
        g[i][mm] = '\0';
    }

    reset();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m[i]; ++j){
            if(g[i][j] == '*'){
                g[i][j] = ' ';
                dfs(i, j);
            }
        }
    }
}

int len(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; ++i){}
    return i;
}

int max(int x, int y){
    if(x > y) return x;
    return y;
}

void scan(){
    n = mm = 0;
    while(gets(g[n])){
        if(g[n][0] == '_') break;
        m[n] = len(g[n]);
        mm = max(mm, m[n]);
        ++n;
    }
    ++mm;
}

void print(){
    for(int i = 0; i < n; ++i){
        int j = mm;

        while(g[i][j - 1] == ' ') --j;
        g[i][j] = '\0';

        cout << g[i] << endl;
    }
    cout << g[n] << endl;
}

int main()
{
    //fileInput();

    int tc;
    scanf("%d", &tc);
    getchar();

    for(int t = 1; t <= tc; ++t){
        scan();
        solve();
        print();
    }

    return 0;
}
