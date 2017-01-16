#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<vector<int> > VoV;
const int mx=1000+5;
VoV g(mx),tg(mx);
bitset<mx> visited,gValid,check;
int top,scc,stk[mx],sccBoss[mx];
 
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
 
void dfs2(int node){
    visited[node]=1;
    sccBoss[node]=scc;
    vector<int> v=tg[node];
 
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs2(v[i]);
        }
    }
}
 
void dfs3(int node){
    visited[node]=1;
    check[sccBoss[node]]=1;
    vector<int> v=g[node];
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs3(v[i]);
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
        for(int i=0; i<1000; ++i) g[i].clear(),tg[i].clear();
        visited.reset();
        gValid.reset();
 
        //scanning graph
        int nodeMax=0,nodeMin=1000;
        for(int i=0; i<n; ++i){
            int k;
            scanf("%d",&k);
 
            for(int j=0; j<k; ++j){
                int u,v;
                scanf("%d %d",&u,&v);
 
                nodeMax=max(nodeMax,max(u,v));
                nodeMin=min(nodeMin,u);
 
                g[u].push_back(v);
                tg[v].push_back(u);
                gValid[u]=1;
                //tgValid[v]=1;
            }
        }
        if(nodeMin){
            printf("Case %d: NO\n",t);
            continue;
        }
 
        //make topo
        top=0;
        for(int i=0; i<=nodeMax; ++i){
            if(gValid[i] and !visited[i]){
                dfs1(i);
            }
        }
 
        //count scc
        scc=0;
        visited.reset();
        while(top--){
            int node=stk[top];
            if(!visited[node]){
                dfs2(node);
                ++scc;
            }
        }
 
        //counting out edge and in edge
        bitset<mx> in,out;
        bool spflag=0;
        for(int i=0; i<=nodeMax; ++i){
            if(gValid[i]){
 
                vector<int> v=g[i];
                bitset<mx> used;
                for(int j=0; j<v.size(); ++j){
                    if(sccBoss[i]!=sccBoss[v[j]] and !used[sccBoss[v[j]]]){
                        used[sccBoss[v[j]]]=1;
 
                        if(in[sccBoss[v[j]]] or out[sccBoss[i]]){
                            spflag=1;
                            break;
                        }
                        in[sccBoss[v[j]]]=1;
                        out[sccBoss[i]]=1;
                    }
                }
                if(spflag) break;
            }
        }
 
        if(spflag){
            printf("Case %d: NO\n",t);
            continue;
        }
 
        //dfs from source node
        visited.reset();
        check.reset();
        dfs3(0);
 
        int kount=0;
        for(int i=0; i<scc; ++i){
            if(check[i]) ++kount;
        }
 
        if(kount==scc) printf("Case %d: YES\n",t);
        else printf("Case %d: NO\n",t);
    }
    return 0;
}
