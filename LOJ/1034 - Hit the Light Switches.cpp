#include <bits/stdc++.h>
 
using namespace std;
 
typedef map<int, vector<int> > uMap;
 
const int mx=1e4+5;
bitset<mx> light;
bitset<mx> color;
bitset<mx> inEdge;
bitset<mx> isVisited;
int sccBoss[mx];
int n,m,sccIndex,sccCount;
 
void dfs(uMap& g, int node){
    light[node]=1;
    vector<int> v=g[node];
 
    for(int i=0; i<v.size(); ++i){
        if(!light[v[i]]){
            dfs(g,v[i]);
        }
    }
}
 
void dfs3(uMap& ng, uMap& tg, int node){
    color[node]=1;
    ng[sccIndex].push_back(node);
    sccBoss[node]=sccIndex;
    vector<int> v=tg[node];
 
    for(int i=0; i<v.size(); ++i){
        if(!color[v[i]]){
            --sccCount;
            dfs3(ng,tg,v[i]);
        }
    }
 
}
 
void dfs2(uMap& g, int node, stack<int>& topo){
    isVisited[node]=1;
    vector<int> v=g[node];
 
    for(int i=0; i<v.size(); ++i){
        if(!isVisited[v[i]]){
            dfs2(g,v[i],topo);
        }
    }
    topo.push(node);
}
 
void makeTopo(uMap& g, stack<int>& topo){
    uMap::iterator it;
    for(it=g.begin(); it!=g.end(); ++it){
        if(!isVisited[it->first]){
            dfs2(g,it->first,topo);
        }
    }
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
 
        scanf("%d %d",&n,&m);
 
        light.reset();
        isVisited.reset();
        color.reset();
        inEdge.reset();
 
        uMap g, tg, ng;
 
        for(int i=0; i<mx; ++i) sccBoss[i]=i;
 
        for(int i=0; i<m; ++i){
            int x,y;
            scanf("%d %d",&x,&y);
 
            g[x].push_back(y);
            tg[y].push_back(x);
        }
 
        stack<int> topo;
        makeTopo(g,topo);
 
        sccCount=n;
        sccIndex=0;
        while(!topo.empty()){
            int node=topo.top();
            topo.pop();
 
            if(!color[node]){
                dfs3(ng,tg,node);
                ++sccIndex;
            }
        }
        //scc count end here
 
        for(uMap::iterator it=g.begin(); it!=g.end(); ++it){
            int x=it->first;
            vector<int> v=it->second;
            for(int i=0; i<v.size(); ++i){
                if(sccBoss[x]!=sccBoss[v[i]]){
                    inEdge[v[i]]=1;
                }
            }
        }
        int incount=0;
 
        for(uMap::iterator it=ng.begin(); it!=ng.end(); ++it){
            bool flag=0;
            vector<int> v=it->second;
            for(int i=0; i<v.size(); ++i){
                if(inEdge[v[i]]){
                    flag=1;
                    break;
                }
            }
            if(flag) ++incount;
        }
 
        int ans=sccCount-incount;
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
