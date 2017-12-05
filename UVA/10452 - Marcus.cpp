#include <iostream>
#include <stdio.h>
using namespace std;

const int mx = 10;
int m, n, prevI, prevJ, newI, newJ;
char g[mx][mx];
char path[] = "IEHOVA#";

void scan(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> g[i][j];
            if(g[i][j] == '@'){
                prevI = i;
                prevJ = j;
            }
        }
    }
}

void findLetter(int index){
    for(int i = 0; i <= prevI; ++i){
        for(int j = 0; j < n; ++j){
            if(g[i][j] == path[index]){
                newI = i;
                newJ = j;
                return;
            }
        }
    }
}

void print(){
    if(prevI != newI){
        cout << "forth";
    }
    else{
        if(prevJ > newJ){
            cout << "left";
        }
        else{
            cout << "right";
        }
    }
}

void update(){
    prevI = newI;
    prevJ = newJ;
}

void solve(){
    for(int i = 0; i < 7; ++i){
        if(i) cout << " ";

        findLetter(i);
        print();
        update();
    }
    cout << endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int i = 0; i < tc; ++i){
        scan();
        solve();
    }

    return 0;
}
