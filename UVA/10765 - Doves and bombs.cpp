#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class ArticulationPoint{
public:
    int node;
    int size;

    bool operator<(const ArticulationPoint& b){
        if(size == b.size)
            return node < b.node;
        return size > b.size;
    }
};

const int mx = 1e4 + 5;
vector<vector<int> > g(mx);
bool visited[mx];
int d[mx], low[mx], parent[mx], etime;
int n, p;
ArticulationPoint ap[mx];

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    etime = 0;
    for(int i = 0; i < mx; ++i){
        g[i].clear();
        visited[i] = false;
        parent[i] = -1;
        ap[i].node = i; ap[i].size = 0;
    }
}

void scan(){
    int u, v;
    while(cin >> u >> v and (~u or ~v)){
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs(int u){
    int child = 0;
    visited[u] = true;
    d[u] = low[u] = ++etime;

    for(auto v : g[u]){
        if(!visited[v]){
            parent[v] = u;
            ++child;

            dfs(v);
            low[u] = min(low[u], low[v]);

            if(parent[u] == -1){
                ap[u].size = child;
            }
            else if(parent[u] != -1 and low[v] >= d[u]){
                ++ap[u].size;
            }
        }
        else if(visited[v] and v != parent[u]){
            low[u] = min(low[u], d[v]);
        }
    }
}

void print(){
    //each node has an ancestor
    for(int i = 1; i < n; ++i){
        ++ap[i].size;
    }

    sort(ap, ap + n);
    for(int i = 0; i < p; ++i){
        cout << ap[i].node << " " << ap[i].size << endl;
    }
    cout << endl;
}

int main()
{
    //file();

    while(cin >> n >> p and (n or p)){
        reset();
        scan();
        dfs(0);
        print();
    }

    return 0;
}
