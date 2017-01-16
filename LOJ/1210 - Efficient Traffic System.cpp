#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<vector<int> > VoV;
const int mx=2e4+5;
VoV g(mx),tg(mx);
int top,sccCount,sccBoss[mx],stk[mx];
bitset<mx> visited;
 
void dfs1(int node){
    visited[node]=1;
    vector<int> v=g[node];
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs1(v[i]);
        }
    }
    stk[top++]=node;
}
 
void dfs2(int node, int scc){
    visited[node]=1;
    sccBoss[node]=scc;
    vector<int> v=tg[node];
 
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs2(v[i],scc);
            --sccCount;
        }
    }
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int n,m;
        scanf("%d %d",&n,&m);
 
        for(int i=0; i<n; ++i){
            g[i].clear();
            tg[i].clear();
        }
        memset(stk,0,sizeof(stk));
        visited.reset();
 
        for(int i=0; i<m; ++i){
            int x,y;
            scanf("%d %d",&x,&y);
 
            --x;--y;
            g[x].push_back(y);
            tg[y].push_back(x);
        }
 
        //topo order
        top=0;
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                dfs1(i);
            }
        }
 
        //scc count
        visited.reset();
        sccCount=n;
        int scc=0;
        for(int i=0; i<n; ++i) sccBoss[i]=i;
 
        while(top--){
            int node=stk[top];
 
            if(!visited[node]){
                dfs2(node,scc);
                ++scc;
            }
        }
 
        if(scc==1){
            printf("Case %d: 0\n",t);
            continue;
        }
 
        //in out set
        bitset<mx> in;
        bitset<mx> out;
        for(int node=0; node<n; ++node){
            vector<int> v=g[node];
            for(int i=0; i<v.size(); ++i){
                if(sccBoss[node]!=sccBoss[v[i]]){
                    in[sccBoss[v[i]]]=1;
                    out[sccBoss[node]]=1;
                }
            }
        }
 
        //in out count
        int mx1=0,mx2=0;
        for(int i=0; i<scc; ++i){
            if(!in[i]) ++mx1;
            if(!out[i]) ++mx2;
        }
 
        printf("Case %d: %d\n",t,max(mx1,mx2));
    }
    return 0;
}
