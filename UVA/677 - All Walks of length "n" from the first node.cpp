#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 12;
int m, n;
int g[mx][mx];
int place[mx];
bool flag;

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void scan(){
    flag = false;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            cin >> g[i][j];
        }
    }
}

void print(){
    flag = true;
    cout << "(";
    for(int i = 0; i <= n; ++i){
        if(i) cout << ",";
        cout << place[i] + 1;
    }
    cout << ")" << endl;
}

bool valid(int node, int kount){
    for(int i = 0; i < kount; ++i){
        if(place[i] == node) return false;
    }
    return true;
}

void dfs(int u, int kount){
    place[kount] = u;
    if(kount == n){
        print();
        return;
    }

    for(int v = 0; v < m; ++v){
        if(g[u][v] and valid(v, kount)){
            dfs(v, kount + 1);
        }
    }
}

void solve(){
    while(cin >> m){
        if(m == -9999){
            cout << endl;
            continue;
        }

        cin >> n;
        scan();

        dfs(0, 0);
        if(!flag) cout << "no walk of length " << n << endl;
    }
}

int main()
{
    //fileInput();
    solve();

    return 0;
}
