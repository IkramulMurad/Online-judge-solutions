#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 30;
char str[5000][mx]; //str size 1000 get run time error
bool g[mx][mx];
bool appear[mx], taken[mx];
int in[mx];
int n, m;

void fileIO(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int len(char s[]){
    int i;
    for(i = 0; s[i]; ++i){}
    return i;
}

int min(int x, int y){
    if(x < y) return x;
    return y;
}

void reset(){
    n = 0;
    m = 0;
    for(int i = 0; i < mx; ++i){
        in[i] = 0;
        appear[i] = taken[i] = false;
        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

void scan(){
    while(cin >> str[n]){
        if(str[n][0] == '#') break;
        ++n;
    }
}

void process(){
    for(int i = 0; i < n; ++i){
        int lens = len(str[i]);
        for(int j = 0; j < lens; ++j){
            int k = str[i][j] - 'A';
            appear[k] = true;
        }
    }

    for(int i = 0; i < mx; ++i){
        if(appear[i]) ++m;
    }

    for(int i = 1; i < n; ++i){
        int j = 0;
        int minlen = min(len(str[i]), len(str[i - 1]));
        while(j < minlen and str[i][j] == str[i - 1][j]){
            ++j;
        }
        if(j < minlen){
            int u = str[i - 1][j] - 'A';
            int v = str[i][j] - 'A';

            if(!g[u][v]) ++in[v];
            g[u][v] = true;
        }
    }
}

void adjust(int u){
    for(int v = 0; v < mx; ++v){
        if(g[u][v]) --in[v];
    }
}

int pick(){
    int idx = 0;
    for(int i = 0; i < mx; ++i){
        if(appear[i] and !taken[i] and in[i] == 0){
            taken[i] = true;
            adjust(i);
            idx = i;
            break;
        }
    }
    return idx;
}

void solve(){
    for(int i = 0; i < m; ++i){
        char c = 'A' + pick();
        cout << c;
    }
    cout << endl;
}

int main()
{
    //fileIO();

    while(true){
        reset();
        scan();

        if(!n) break;

        process();
        solve();
    }

    return 0;
}
