#include <bits/stdc++.h>
using namespace std;
 
struct Edge{
    int v, flow, cap, revIdx;
   
    Edge(){}
    Edge(int v, int flow, int cap, int revIdx) : v(v), flow(flow), cap(cap), revIdx(revIdx) {}
};
 
struct Data{
    bool type;
    int label, dist;
 
    void make(bool type, int label, int dist){
        this->type = type;
        this->label = label;
        this->dist = dist;
    }
};
 
typedef vector <vector <Edge> > vve;
const int inf = 1e9;
const int mx = 205;
int level[mx];
int start[mx];
vve g(mx);
int n, d;
Data table[mx];
 
void addEdge(int u, int v, int c, vve &g){
    Edge a(v, 0, c, g[v].size());
    Edge b(u, 0, 0, g[u].size());
 
    g[u].push_back(a);
    g[v].push_back(b);
}
 
bool bfs(int s, int t){
    memset(level, -1, sizeof(level));
    level[s] = 0;
 
    queue <int> q;
    q.push(s);
 
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < g[u].size(); ++i){
            Edge &edge = g[u][i];
            int &v = edge.v;
            if(level[v] == -1 and edge.flow < edge.cap){
                q.push(v);
                level[v] = level[u] + 1;
                if(v == t) return true;
            }
        }
    }
    return false;
}
 
int dfs(int u, int t, int prevFlow){
    if(u == t) return prevFlow;
 
    for(int &i = start[u]; i < g[u].size(); ++i){
        Edge &edge = g[u][i];
        int &v = edge.v;
 
        if(level[v] == level[u] + 1 and edge.flow < edge.cap){
            int minFlowTillNow = min(prevFlow, edge.cap - edge.flow);
            int minPathFlow = dfs(v, t, minFlowTillNow);
            if(minPathFlow > 0){
                edge.flow += minPathFlow;
                g[v][edge.revIdx].flow -= minPathFlow;
                return minPathFlow;
            }
        }
    }
    return 0;
}
 
int dinic(int s, int t){
    if(s == t) return 0;
    int maxFlow = 0;
    while(bfs(s, t)){
        memset(start, 0, sizeof(start));
        while(int flow = dfs(s, t, inf)){
            maxFlow += flow;
        }
    }
    return maxFlow;
}
 
void makeGraph(int mid){
    int rng = table[n + 1].label;
    for(int i = 0; i <= rng; ++i){
        g[i].clear();
    }
    for(int i = 0; i <= n + 1; ++i){
        if(table[i].type){
            addEdge(table[i].label, table[i].label + 1, 1, g);
        }
        for(int j = i + 1; j <= n + 1; ++j){
            if(table[j].dist - table[i].dist > mid) break;
            addEdge(table[i].label + table[i].type, table[j].label, 2, g);
            //cout << "u: " << table[i].label + table[i].type << ", v: " << table[j].label << endl;
        }
    }
}
 
int binSearch(){
    int lo = 0, hi = d, ret = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
 
        makeGraph(mid);
        int flow = dinic(0, table[n + 1].label);
        //cout << "mid: " << mid << ", flow: " << flow << endl;
 
        if(flow < 2){
            lo = mid + 1;
        }
        else{
            ret = mid;
            hi = mid - 1;
        }
    }
    return ret;
}
 
int main(){
    //freopen("in.txt", "r", stdin);
 
    int tc;
    scanf("%d", &tc);
 
    for(int t = 1; t <= tc; ++t){
        string line, s;
        scanf("%d %d", &n, &d);
        if(n){
            getchar();
            getline(cin, line);
        }
       
        for(int i = 0; i < line.size(); ++i){
            if(line[i] == '-'){
                line[i] = ' ';
            }
        }
 
        int idx = 0, label = 0, dist;
        table[idx++].make(0, label++, 0);
       
        stringstream sin(line);
        while(sin >> s >> dist){
            table[idx++].make(s[0] == 'S', label++, dist);
            if(s[0] == 'S') ++label;
        }
        table[idx++].make(0, label++, d);
 
        int ans = binSearch();
        printf("Case %d: %d\n", t, ans);
    }
 
    return 0;
}
