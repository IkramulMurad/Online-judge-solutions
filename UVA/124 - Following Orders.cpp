#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 30;
bool g[mx][mx];
bool appear[mx];
char place[mx];
int in[mx];
int n;

void fileIO(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

bool checkBit(int num, int pos){
    return (num & (1 << pos));
}

int setBit(int num, int pos){
    return (num | (1 << pos));
}

int len(char s[]){
    int i;
    for(i = 0; s[i]; ++i){}
    return i;
}

void reset(){
    n = 0;
    for(int i = 0; i < mx; ++i){
        appear[i] = false;
        in[i] = 0;
        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

void process(char var[], char cons[]){
    int lenv = len(var);
    int lenc = len(cons);

    for(int i = 0; i < lenv; ++i){
        if(var[i] == ' ') continue;
        ++n;
        int k = var[i] - 'a';
        appear[k] = true;
    }

    int rng = (lenc + 1) / 4;
    for(int i = 0, j = 0; i < rng; ++i){
        if(i) ++j;

        int u = cons[j] - 'a';
        int v = cons[j + 2] - 'a';

        if(!g[u][v]) ++in[v];
        g[u][v] = true;

        j += 3;
    }
}

void copyArr(int tmp[], int in[]){
    for(int i = 0; i < mx; ++i){
        tmp[i] = in[i];
    }
}

void adjust(int u, int in[]){
    for(int v = 0; v < mx; ++v){
        if(g[u][v]) --in[v];
    }
}

void print(){
    for(int i = 0; i < n; ++i){
        cout << place[i];
    }
    cout << endl;
}

void topo(int pos, int taken, char c, int in[]){
    place[pos] = c;

    if(pos == n - 1){
        print();
        return;
    }

    int u = c - 'a';
    int tmp[mx];

    copyArr(tmp, in);
    adjust(u, tmp);

    for(int i = 0; i < mx; ++i){
        if(appear[i] and !checkBit(taken, i) and tmp[i] == 0){
            topo(pos + 1, setBit(taken, i), 'a' + i, tmp);
        }
    }
}

void solve(){
    for(int i = 0; i < mx; ++i){
        if(appear[i] and in[i] == 0){
            topo(0, setBit(0, i), 'a' + i, in);
        }
    }
}

int main()
{
    //fileIO();

    int t = 0;
    char var[40], cons[205];
    while(gets(var)){
        gets(cons);

        if(t++) cout << endl;
        reset();
        process(var, cons);
        solve();
    }

    return 0;
}
