#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<vector<int> > vov;
const int mx=1005;
vov g(mx);
int used[mx];
bitset<mx> visited;
 
void dfs(int node){
    visited[node]=1;
    ++used[node];
    vector<int> v=g[node];
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs(v[i]);
        }
    }
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int k,n,m;
        scanf("%d %d %d",&k,&n,&m);
        int source[k],x;
        for(int i=0; i<k; ++i){
            scanf("%d",&x);
            --x;
            source[i]=x;
        }
 
        //clear
        for(int i=0; i<n; ++i) g[i].clear();
        memset(used,0,sizeof(used));
 
        //scanning graph
        int u,v;
        for(int i=0; i<m; ++i){
            scanf("%d %d",&u,&v);
            --u; --v;
            g[u].push_back(v);
        }
 
        //process
        for(int i=0; i<k; ++i){
            visited.reset();
            dfs(source[i]);
        }
 
        int ans=0;
        for(int i=0; i<n; ++i){
            if(used[i]==k) ++ans;
        }
 
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
