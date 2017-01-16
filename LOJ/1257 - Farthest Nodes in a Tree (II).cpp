#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=3e4+5;
vector<vector<int> > g(mx), c(mx);
bitset<mx> visited;
int a[mx],b[mx];
int firstEnd, secondEnd, nodeMax, edgeMax;
 
void dfs(int node, int cost){
    visited[node]=1;
 
    if(cost>edgeMax){
        edgeMax=cost;
        nodeMax=node;
        //cout<<cost<<" "<<node<<endl;
    }
 
    vector<int> v=g[node];
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs(v[i],cost+c[node][i]);
        }
    }
}
 
void findEnd(){
    edgeMax=nodeMax=0;
    visited.reset();
    dfs(0,0);
    firstEnd=nodeMax;
    //cout<<firstEnd<<" ";
    edgeMax=nodeMax=0;
    visited.reset();
    dfs(firstEnd,0);
    secondEnd=nodeMax;
    //cout<<secondEnd<<endl;
}
 
void dfs2(int node, int cost, int a[]){
    visited[node]=1;
    a[node]=cost;
 
    vector<int> v=g[node];
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs2(v[i],cost+c[node][i],a);
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
        for(int i=0; i<n; ++i) g[i].clear(), c[i].clear();
 
        //scanning graph
        int u,v,w;
        for(int i=1; i<n; ++i){
            scanf("%d %d %d",&u,&v,&w);
 
            g[u].push_back(v);
            g[v].push_back(u);
 
            c[u].push_back(w);
            c[v].push_back(w);
        }
 
        //find ends
        findEnd();
 
        //dfs from 2 ends
        visited.reset();
        dfs2(firstEnd,0,a);
 
        visited.reset();
        dfs2(secondEnd,0,b);
 
        printf("Case %d:\n",t);
        for(int i=0; i<n; ++i){
            printf("%d\n",max(a[i],b[i]));
        }
    }
    return 0;
}
