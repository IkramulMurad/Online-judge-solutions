#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6;
int n;
int par[mx];

void makeSet(int u){
    par[u] = u;
}

int findPar(int u){
    if(u == par[u]) return u;
    return par[u] = findPar(par[u]);
}

void makeFriend(int u, int v){
    u = findPar(u);
    v = findPar(v);

    if(u != v){
        par[v] = u;
    }
}

bool isCon(int u, int v){
    u = findPar(u);
    v = findPar(v);

    return (u == v);
}

void init(){
    for(int i = 0; i < mx; ++i) makeSet(i);
}

void solve(){
    init();

    int suc = 0, un = 0;
    cin >> n;

    getchar();
    while(true){
        string s;
        getline(cin, s);
        if(s[0] == '\0') break;

        stringstream ss(s);

        char op;
        int u, v;
        ss >> op >> u >> v;

        if(op == 'c'){
            makeFriend(u, v);
        }
        else if(op == 'q'){
            if(isCon(u, v)) ++suc;
            else ++un;
        }
    }

    cout << suc << "," << un << endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    getchar();

    for(int t = 1; t <= tc; ++t){
        if(t > 1) cout << endl;
        solve();
    }

    return 0;
}
