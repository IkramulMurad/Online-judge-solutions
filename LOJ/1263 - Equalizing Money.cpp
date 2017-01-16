#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=1005;
vector<vector<int> > g(mx);
bitset<mx> visited;
int dollar[mx], nodeKount, nodeVals;
 
void dfs(int node){
    visited[node]=1;
    ++nodeKount;
    nodeVals+=dollar[node];
 
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
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; ++i) scanf("%d",dollar+i);
 
        //clear
        for(int i=0; i<n; ++i) g[i].clear();
        visited.reset();
 
        //scanning graph
        int u,v;
        for(int i=0; i<m; ++i){
            scanf("%d %d",&u,&v);
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
 
        //process
        int avg;
        bool flag=false, impossible=false;
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                nodeKount=nodeVals=0;
                dfs(i);
                if(nodeVals%nodeKount) impossible=true;
                else{
                    if(flag and nodeVals/nodeKount!=avg){
                        impossible=true;
                    }
                    else{
                        avg=nodeVals/nodeKount;
                        flag=true;
                    }
                }
            }
 
            if(impossible) break;
        }
 
        printf("Case %d: ",t);
        impossible?printf("No\n"):printf("Yes\n");
    }
    return 0;
}
