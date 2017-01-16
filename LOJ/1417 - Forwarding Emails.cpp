#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<vector<int> > VoV;
const int mx=5e4+5;
VoV g(mx), tg(mx);
bitset<mx> visited;
int top, kount, sz[mx], stk[mx], sccBoss[mx], mn[mx];
 
void dfs1(int node){
    visited[node]=1;
    for(int i=0; i<g[node].size(); ++i){
        int d=g[node][i];
        if(!visited[d]){
            dfs1(d);
        }
    }
    stk[top++]=node;
}
 
void dfs2(int node, int scc){
    visited[node]=1;
    sccBoss[node]=scc;
    mn[scc]=min(mn[scc],node);
    sz[scc]++;
 
    for(int i=0; i<tg[node].size(); ++i){
        int d=tg[node][i];
        if(!visited[d]){
            dfs2(d,scc);
        }
    }
}
 
void dfs3(int node, bitset<mx>& used){
    used[sccBoss[node]]=1;
    kount+=sz[sccBoss[node]];
 
    vector<int> v=g[node];
    for(int i=0; i<v.size(); ++i){
        if(!used[sccBoss[v[i]]]){
            dfs3(v[i],used);
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
        for(int i=0; i<n; ++i){
            g[i].clear();
            tg[i].clear();
        }
        visited.reset();
        memset(sz,0,sizeof(sz));
        fill(mn,mn+mx,mx);
 
        //scanning graph
        for(int i=0; i<n; ++i){
            int u,v;
            scanf("%d %d",&u,&v);
 
            --u; --v;
            g[u].push_back(v);
            tg[v].push_back(u);
        }
 
        //make topo
        top=0;
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                dfs1(i);
            }
        }
 
        //count scc
        visited.reset();
        int scc=0;
        while(top--){
            int node=stk[top];
            if(!visited[node]){
                dfs2(node,scc);
                ++scc;
            }
        }
 
        //counting max range
        bitset<mx> check;
        int ans,maxi=0;
        for(int i=0; i<n; ++i){
            kount=0;
            if(!check[sccBoss[i]]){
                check[sccBoss[i]]=1;
 
                bitset<mx> used;
                dfs3(i,used);
 
                if(kount>maxi){
                    maxi=kount;
                    ans=mn[sccBoss[i]];
                }
            }
        }
 
        printf("Case %d: %d\n",t,ans+1);
    }
    return 0;
}
