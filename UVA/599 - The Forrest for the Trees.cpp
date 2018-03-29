#include <bits/stdc++.h>
using namespace std;

const int mx = 30;
vector <vector <int> > g(mx);
bool visited[mx];
int tree, acorn;

int toInt(char c){ return int(c - 'A'); }

void reset(){
    tree = acorn = 0;
    for(int i = 0; i < mx; ++i){
        visited[i] = false;
        g[i].clear();
    }
}

void scan(){
    while(true){
        string s;
        cin >> s;
        if(s[0] == '*') break;

        g[toInt(s[1])].push_back(toInt(s[3]));
        g[toInt(s[3])].push_back(toInt(s[1]));
    }
}

void print(){
    printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
}

void dfs(int u){
    visited[u] = true;

    for(auto v : g[u]){
        if(!visited[v]) dfs(v);
    }
}

void solve(){
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i += 2){
        if(!g[toInt(s[i])].size()){
            ++acorn;
        }
    }

    for(int i = 0; i < 26; ++i){
        if(g[i].size() and !visited[i]){
            ++tree;
            dfs(i);
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
