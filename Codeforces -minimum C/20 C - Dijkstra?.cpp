#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,int> II;
const LL inf=2e17;
const int mx=1e5+5;
vector<vector<int> > g(mx),c(mx);
set<II> pq;
vector<int> path;
bitset<mx> visited,taken;
int n,m;
int p[mx];
LL dist[mx];

void clr(){
    for(int i=0; i<mx; ++i){
        g[i].clear();
        c[i].clear();
    }
    pq.clear();
    path.clear();
    visited.reset();
    taken.reset();
}

void init(){
    for(int i=0; i<=n; ++i){
        dist[i]=inf;
        p[i]=-1;
    }
    dist[1]=0;

    /*for(int i=1; i<=n; ++i){
        pq.insert({dist[i],i});
    }*/

}

void print(){
    cerr<<"Size: "<<pq.size()<<endl;
    cerr<<"Node: ";
    for(auto it=pq.begin(); it!=pq.end(); ++it){
        cerr<<setw(5)<<it->second;
    }
    cerr<<endl;
    cerr<<"Cost: ";
    for(auto it=pq.begin(); it!=pq.end(); ++it){
        cerr<<setw(5)<<it->first;
    }
    cerr<<endl;
}

void dijkstra(){
    init();
    pq.insert({dist[1],1});
    while(!pq.empty()){
        int node=pq.begin()->second;
        int cost=pq.begin()->first;
        pq.erase(pq.begin());

        if(node==n) break;
        taken[node]=1;

        vector<int> v=g[node];
        vector<int> w=c[node];

        for(int i=0; i<v.size(); ++i){
            if(!taken[v[i]] and dist[v[i]]>(LL)cost+w[i]){
                II x(dist[v[i]],v[i]);
                auto it=pq.find(x);
                if(it!=pq.end()){
                    pq.erase(it);
                }
                dist[v[i]]=(LL)cost+w[i];
                p[v[i]]=node;

                pq.insert({dist[v[i]],v[i]});

                //print();
            }
        }
    }

    int x=n;
    while(true){
        path.push_back(x);
        x=p[x];
        if(x==-1) break;
    }
}

void dfs(int node){
    visited[node]=1;

    vector<int> v=g[node];
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs(v[i]);
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    while(cin>>n>>m){
        clr();

        for(int i=0; i<m; ++i){
            int u,v,w;
            cin>>u>>v>>w;

            g[u].push_back(v);
            g[v].push_back(u);

            c[u].push_back(w);
            c[v].push_back(w);
        }

        dfs(1);
        if(!visited[n]){
            cout<<-1<<endl;
            continue;
        }

        dijkstra();

        for(int i=path.size()-1; i>=0; --i){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
