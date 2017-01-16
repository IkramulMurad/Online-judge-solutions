#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=102;
vector<vector<int> > g(mx);
int c[mx][mx];
bool path[mx][mx];
int top, stk[mx];
bitset<mx> visited;
 
void clr(){
    for(int i=0; i<mx; ++i){
        for(int j=0; j<mx; ++j){
            path[i][j]=0;
        }
    }
}
 
void dfs(int node){
    visited[node]=1;
    vector<int> v=g[node];
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs(v[i]);
        }
    }
    stk[top++]=node;
 
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int n;
        scanf("%d",&n);
 
        //clear
        for(int i=0; i<n; ++i) g[i].clear();
        visited.reset();
        clr();
        int ans1=0, ans2=0;
 
        //scanning graph
        int u,v,w;
        for(int i=0; i<n; ++i){
            scanf("%d %d %d",&u,&v,&w);
            --u; --v;
 
            g[u].push_back(v);
            g[v].push_back(u);
 
            c[u][v]=c[v][u]=w;
            path[u][v]=1;
        }
 
        //proces
        top=0;
        dfs(0);
 
        int idx=top-1;
        while(--top){
            int node=stk[top];
            int d=stk[top-1];
            if(path[node][d]){
                ans1+=c[node][d];
            }
            else ans2+=c[node][d];
        }
        if(path[stk[0]][stk[idx]]) ans1+=c[stk[0]][stk[idx]];
        else ans2+=c[stk[0]][stk[idx]];
 
        printf("Case %d: %d\n",t,min(ans1,ans2));
    }
    return 0;
}
