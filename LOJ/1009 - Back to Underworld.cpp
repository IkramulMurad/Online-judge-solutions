#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<vector<int> > VoV;
const int mx=2e4+5;
int a,b;
bitset<mx> visited,valid;
VoV g(mx);
 
void dfs(int node, bool flag){
    visited[node]=1;
    vector<int> v=g[node];
 
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs(v[i],!flag);
        }
    }
    if(flag) ++a;
    else ++b;
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
        valid.reset();
        for(int i=0; i<mx; ++i) g[i].clear();
 
        //scanning graph
        int nodeMax=0;
        for(int i=0; i<n; ++i){
            int u,v;
            scanf("%d %d",&u,&v);
 
            --u; --v;
            nodeMax=max(nodeMax,max(u,v));
            g[u].push_back(v);
            g[v].push_back(u);
            valid[u]=valid[v]=1;
        }
 
        //process
        a=b=0;
        int ans=0;
        for(int i=0; i<=nodeMax; ++i){
            if(valid[i] and !visited[i]){
                dfs(i,0);
                ans+=max(a,b);
                a=b=0;
            }
        }
 
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
