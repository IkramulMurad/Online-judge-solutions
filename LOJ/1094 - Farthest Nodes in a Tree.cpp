#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<vector<int> > VoV;
const int mx=3e4+5;
VoV g(mx),c(mx);
bitset<mx> visited;
int oneEnd;
long long large;
 
void dfs(int node, long long total){
    visited[node]=1;
    vector<int> v=g[node];
    if(total>large){
        large=total;
        oneEnd=node;
    }
 
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs(v[i],total+c[node][i]);
        }
    }
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int n;
        scanf("%d",&n);
 
        //clear
        visited.reset();
        for(int i=0; i<n; ++i) g[i].clear(),c[i].clear();
 
        //scanning graph
        int u,v,w;
        for(int i=1; i<n; ++i){
            scanf("%d %d %d",&u,&v,&w);
 
            g[u].push_back(v);
            g[v].push_back(u);
 
            c[u].push_back(w);
            c[v].push_back(w);
        }
 
        //find one end
        large=oneEnd=0;
        dfs(0,0);
 
        //find total max
        visited.reset();
        large=0;
        dfs(oneEnd,0);
 
        printf("Case %d: %lld\n",t,large);
    }
 
    return 0;
}
