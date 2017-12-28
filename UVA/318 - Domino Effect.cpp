#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> II;
const int mx = 505;
const int inf = 1e9;
vector<vector<int> > g(mx), cost(mx);
int dist[mx];
bool visited[mx];
int n, m;
int keyNode, keyN1, keyN2;
double mxNode, mxEdge;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void clr(){
    for(int i = 0; i < mx; ++i){
        g[i].clear(); cost[i].clear();
    }
}

void reset(){
    keyN1 = keyN2 = keyNode = 1;
    mxNode = mxEdge = 0.0;
    for(int i = 0; i < mx; ++i){
        dist[i] = inf;
        visited[i] = false;
    }
}

bool scan(){
    cin >> n >> m;
    if(!n and !m) return false;

    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back(v);
        g[v].push_back(u);

        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    return true;
}

void dijkstra(){
    dist[1] = 0;
    II source(dist[1], 1);

    multiset<II> pq;
    pq.insert(source);

    while(!pq.empty()){
        II top = *pq.begin();
        int u = top.second;
        pq.erase(pq.begin());

        if(visited[u]) continue;
        visited[u] = true;

        for(int i = 0; i < g[u].size(); ++i){
            int v = g[u][i], w = cost[u][i];

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;

                II x(dist[v], v);
                pq.insert(x);
            }
        }
    }
}

void compute(){
    for(int i = 1; i <= n; ++i){
        if(mxNode < dist[i]){
            mxNode = dist[i];
            keyNode = i;
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < g[i].size(); ++j){
            int u = i, v = g[i][j];

            int filledSegment = max(dist[u], dist[v]) - min(dist[u], dist[v]);
            int remainedSegment = cost[i][j] - filledSegment;

            double tmpEdge =  (double)max(dist[u], dist[v]) + (double)remainedSegment / 2;
            if(mxEdge < tmpEdge){
                mxEdge = tmpEdge;
                keyN1 = min(u, v); keyN2 = max(u, v);
            }
        }
    }
}

void print(int t){
    cout << "System #" << t << endl;
    if(mxNode >= mxEdge){
        cout << "The last domino falls after ";
        cout << fixed << setprecision(1) << mxNode;
        cout << " seconds, at key domino " << keyNode << "." << endl;
    }
    else{
        cout << "The last domino falls after ";
        cout << fixed << setprecision(1) << mxEdge;
        cout << " seconds, between key dominoes " << keyN1 << " and " << keyN2 << "." << endl;
    }
    cout << endl;
}

int main()
{
    //file();

    int t = 0;
    while(scan()){
        reset();
        dijkstra();
        compute();
        print(++t);
        clr();
    }

    return 0;
}
