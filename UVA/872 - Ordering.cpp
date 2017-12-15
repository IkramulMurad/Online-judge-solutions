#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 26;
bool g[mx][mx];
bool appear[mx];
char place[mx];
int in[mx];
bool impossible;
int n;

void fileIO(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int charToNum(char c){
    return int(c - 'A');
}

char numToChar(int i){
    return char('A' + i);
}

int len(char s[]){
    int i;
    for(i = 0; s[i]; ++i){}
    return i;
}

bool checkBit(int num, int pos){
    return (num & (1 << pos));
}

int setBit(int num, int pos){
    return (num | (1 << pos));
}

void reset(){
    for(int i = 0; i < mx; ++i){
        appear[i] = false;
        in[i] = 0;
        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

void scan(){
    char blank[100], var[50], cons[250];
    gets(blank); gets(var); gets(cons);

    int m;
    n = (len(var) + 1) / 2;
    m = (len(cons) + 1) / 4;

    for(int i = 0, j = 0; i < n; ++i, ++j){
        if(i) ++j;

        int idx = charToNum(var[j]);
        appear[idx] = true;
    }

    for(int i = 0, j = 0; i < m; ++i){
        if(i) ++j;

        int u = charToNum(cons[j]);
        int v = charToNum(cons[j + 2]);

        g[u][v] = true;
        ++in[v];

        j += 3;
    }
}

void print(){
    for(int i = 0; i < n; ++i){
        if(i) cout << " ";
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

    int temp[mx];
    for(int i = 0; i < mx; ++i){
        temp[i] = in[i];
    }

    int u = charToNum(c);
    for(int v = 0; v < mx; ++v){
        if(g[u][v]) --temp[v];
    }

    for(int v = 0; v < mx; ++v){
        if(appear[v] and temp[v] == 0 and !checkBit(taken, v)){
            topo(pos + 1, setBit(taken, v), numToChar(v), temp);
        }
    }
}

bool check(){
    for(int i = 0; i < mx; ++i){
        if(appear[i] and in[i] == 0){
            return false;
        }
    }
    return true;
}

void solve(){
    impossible = check();

    if(impossible){
        cout << "NO" << endl;
        return;
    }

    for(int i = 0; i < mx; ++i){
        if(appear[i] and in[i] == 0){
            topo(0, setBit(0, i), numToChar(i), in);
        }
    }
}

int main()
{
    //fileIO();

    int tc;
    cin >> tc;
    getchar();

    for(int t = 1; t <= tc; ++t){
        if(t > 1) cout << endl;
        reset();
        scan();
        solve();
    }

    return 0;
}
