#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> II;
typedef pair<int,II> III;
const int inf=2e9;
const int mx=5005;
vector<vector<int> > g(mx),c(mx);
vector<bitset<mx> > visited(2);
int n,m;
int dist[2][mx];

void clr(){
    for(int i=0; i<mx; ++i){
        g[i].clear();
        c[i].clear();
    }
}

void scan(){
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; ++i){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);

        g[u].push_back(v);
        g[v].push_back(u);

        c[u].push_back(w);
        c[v].push_back(w);
    }
}

void init(){
    for(int i=0; i<mx; ++i){
        dist[0][i]=inf;
        dist[1][i]=inf;
    }
    dist[0][1]=0;

    visited[0].reset();
    visited[1].reset();
}

void print(){
    for(int i=1; i<=n; ++i){
        cerr<<dist[0][i]<<" ";
    }
    cerr<<endl;

    for(int i=1; i<=n; ++i){
        cerr<<dist[1][i]<<" ";
    }
    cerr<<endl;
}

int dijkstra(){
    init();

    priority_queue<III,vector<III>,greater<III> > pq;
    pq.push({0,{0,1}});

    while(!pq.empty()){
        int node=pq.top().second.second;
        int type=pq.top().first;
        pq.pop();

        if(visited[type][node]) continue;
        visited[type][node]=1;

        vector<int> v=g[node];
        vector<int> w=c[node];

        for(int i=0; i<v.size(); ++i){
            int alt=dist[type][node]+w[i];
            if(alt<dist[0][v[i]]){
                dist[1][v[i]]=dist[0][v[i]];
                dist[0][v[i]]=alt;

                pq.push({1,{dist[1][v[i]],v[i]}});
                pq.push({0,{dist[0][v[i]],v[i]}});
            }
            else if(alt>dist[0][v[i]] and alt<dist[1][v[i]]){
                dist[1][v[i]]=alt;
                pq.push({1,{dist[1][v[i]],v[i]}});
            }
        }
    }

    //print();

    return dist[1][n];
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; ++t){
        clr();
        scan();

        int ans=dijkstra();

        printf("Case %d: %d\n",t,ans);
    }

    return 0;
}
