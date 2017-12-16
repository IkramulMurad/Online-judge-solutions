#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
char drinks[mx][mx];
bool g[mx][mx];
bool taken[mx];
int in[mx];
int n;

void fileIO(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int len(char s[]){
    int i;
    for(i = 0; s[i]; ++i){}
    return i;
}

bool match(char s[], char t[]){
    int lens = len(s);
    int lent = len(t);

    if(lens != lent) return false;

    for(int i = 0; i < lens; ++i){
        if(s[i] != t[i]) return false;
    }

    return true;
}

int getIndex(char s[]){
    int idx = -1; //rte
    for(int i = 0; i < n; ++i){
        if(match(s, drinks[i])){
            idx = i;
            break;
        }
    }
    return idx;
}

void reset(){
    for(int i = 0; i < mx; ++i){
        in[i] = 0;
        taken[i] = false;
        for(int j = 0; j < mx; ++j){
            g[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        cin >> drinks[i];
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; ++i){
        char s[mx], t[mx];
        cin >> s >> t;

        int u = getIndex(s);
        int v = getIndex(t);

        if(!g[u][v]) ++in[v];
        g[u][v] = true;
    }
}

void printCase(int t){
    cout << "Case #" << t << ": Dilbert should drink beverages in this order:";
}

void print(int idx){
    cout << " " << drinks[idx];
}

void adjust(int u){
    for(int v = 0; v < n; ++v){
        if(g[u][v]) --in[v];
    }
}

int pick(){
    int idx = -1;
    for(int i = 0; i < n; ++i){
        if(!taken[i] and in[i] == 0){
            taken[i] = true;
            adjust(i);
            idx = i;
            break;
        }
    }
    return idx;
}

void solve(){
    for(int i = 0; i < n; ++i){
        int idx = pick();
        print(idx);
    }

    cout << "." << endl << endl;
}

int main()
{
    //fileIO();

    int t = 0;
    while(cin >> n){
        reset();
        scan();
        printCase(++t);
        solve();
    }

    return 0;
}
