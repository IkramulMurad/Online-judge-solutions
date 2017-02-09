#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> II;
typedef long long LL;
const int mx=1e4+5;
vector<vector<int> > g(mx),c(mx);
bitset<mx> visited;
int n,m,A;
 
int prims(int source){
    priority_queue<II,vector<II>,greater<II> > pq;
    pq.push(make_pair(0,source));
 
    int ans=0;
 
    while(!pq.empty()){
        int node=pq.top().second;
        int cost=pq.top().first;
        pq.pop();
 
        if(cost>=A) return ans;
        if(!visited[node]){
            ans+=cost;
            visited[node]=1;
        }
 
        vector<int> v=g[node];
        vector<int> w=c[node];
 
        for(int i=0; i<v.size(); ++i){
            if(!visited[v[i]]){
                pq.push(make_pair(w[i],v[i]));
            }
        }
    }
 
    return ans;
}
 
int main()
{
 
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
 
    int tc;
    cin>>tc;
 
    for(int t=1; t<=tc; ++t){
        cin>>n>>m>>A;
 
        for(int i=0; i<=n; ++i){
            g[i].clear();
            c[i].clear();
            visited.reset();
        }
 
        for(int i=0; i<m; ++i){
            int u,v,w;
            cin>>u>>v>>w;
 
            g[u].push_back(v);
            g[v].push_back(u);
 
            c[u].push_back(w);
            c[v].push_back(w);
        }
 
        LL ans=0,kount=0;
        for(int i=1; i<=n; ++i){
            if(!visited[i]){
                ans+=prims(i)+A;
                ++kount;
            }
        }
 
        printf("Case %d: %lld %lld\n",t,ans,kount);
    }
 
    return 0;
}
