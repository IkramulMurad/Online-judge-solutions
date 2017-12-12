#include <iostream>
#include <cstdio>
using namespace std;

char g[50][100];
int n, m[50];
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

bool valid(int i, int j){
    if(i >= 0 and j >= 0 and i < n and j < m[i]) return true;
    return false;
}

void dfs(int i, int j, char color){
    g[i][j] = color;

    for(int k = 0; k < 4; ++k){
        int newI = i + x[k];
        int newJ = j + y[k];
        if(valid(newI, newJ) and g[newI][newJ] != 'X' and g[newI][newJ] != color){
            dfs(newI, newJ, color);
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m[i]; ++j){
            if(g[i][j] != ' ' and g[i][j] != 'X'){
                dfs(i, j, g[i][j]);
            }
        }
    }
}

int len(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; ++i){}
    return i;
}

void print(){
    for(int i = 0; i <= n; ++i){
        cout << g[i] << endl;
    }
}

int main()
{
    //fileInput();

    while(true){
        n = 0;
        while(true){
            if(!gets(g[n])) return 0;
            if(g[n][0] == '_') break;

            m[n] = len(g[n]);
            ++n;
        }

        solve();
        print();
    }

    return 0;
}
