#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

const int mx = 1005;
int n, m, monkey;
int a[mx][mx];
char g[mx][mx];
bool visited[mx][mx];
int align[mx];
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    monkey = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

bool valid(int i, int j){
    if(i >= 0 and j >= 0 and i < n and j < m) return true;
    return false;
}

void dfs(int i, int j, char spec){
    visited[i][j] = true;
    a[i][j] = monkey;

    for(int k = 0; k < 8; ++k){
        int newI = i + x[k];
        int newJ = j + y[k];
        if(valid(newI, newJ) and !visited[newI][newJ] and g[newI][newJ] == spec){
            dfs(newI, newJ, spec);
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j]){
                ++monkey;
                dfs(i, j, g[i][j]);
            }
        }
    }
}

int max(int x, int y){
    if(x > y) return x;
    return y;
}

void makeAlignTable(){
    for(int i = 0; i < m; ++i){
        int hi = 0;
        for(int j = 0; j < n; ++j){
            hi = max(hi, a[j][i]);
        }

        int x = 2;
        while(hi / 10){
            ++x;
            hi /= 10;
        }
        align[i] = x;
    }
}

void print(){
    makeAlignTable();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(j) cout << setw(align[j]);
            else cout << setw(align[j] - 1);
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << "%" << endl;
}

int len(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; ++i){}
    return i;
}

int main()
{
    //fileInput();

    while(true){
        char line[mx];
        n = m = 0;
        while(gets(line)){
            if(line[0] == '%') break;

            m = 0;
            for(int i = 0; line[i] != '\0'; ++i){
                if(line[i] != ' '){
                    g[n][m++] = line[i];
                }
            }
            ++n;
        }

        reset();
        solve();
        print();

        if(line[0] != '%') break;
    }

    return 0;
}
