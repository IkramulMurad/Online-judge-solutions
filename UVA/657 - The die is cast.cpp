#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int mx = 55;
char g[mx][mx];
bool visited[mx][mx];
int n, m;
int item, ans, place[mx];
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    item = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void dfs2(int i, int j){
    g[i][j] = '*';
    for(int k = 0; k < 4; ++k){
        int newI = i + x[k];
        int newJ = j + y[k];
        if(valid(newI, newJ) and g[newI][newJ] == 'X'){
            dfs2(newI, newJ);
        }
    }
}

void dfs1(int i, int j){
    visited[i][j] = true;

    for(int k = 0; k < 4; ++k){
        int newI = i + x[k];
        int newJ = j + y[k];
        if(valid(newI, newJ) and g[newI][newJ] == 'X'){
            ++ans;
            dfs2(newI, newJ);
        }
        if(valid(newI, newJ) and !visited[newI][newJ] and g[newI][newJ] == '*'){
            dfs1(newI, newJ);
        }
    }
}

void solve(){
    reset();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(g[i][j] == '*' and !visited[i][j]){
                ans = 0;
                dfs1(i, j);
                place[item++] = ans;
            }
        }
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        cin >> g[i];
    }
}

void print(int t){
    sort(place, place + item);
    cout << "Throw " << t << endl;
    for(int i = 0; i < item; ++i){
        if(i) cout << " ";
        cout << place[i];
    }
    cout << endl << endl;
}

int main()
{
    //fileInput();

    int t = 0;
    while(cin >> m >> n and (n or m)){
        scan();
        solve();
        print(++t);
    }

    return 0;
}
