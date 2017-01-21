#include <bits/stdc++.h>

using namespace std;

const int mx=105;

vector<vector<int> > g(mx),cost(mx);
bitset<mx> visited;
bool flag=0;
int mostCost,finalCost,hi,lo;

void dfs(int node, int dest, int maxCost){
    visited[node]=1;

    if(node==dest){
        flag=1;
        finalCost=mostCost;
        return;
    }

    vector<int> a=g[node];
    vector<int> c=cost[node];

    for(int i=0; i<a.size(); ++i){
        int v=a[i];
        int cst=c[i];
        if(!visited[v] and cst<=maxCost){
            mostCost=max(mostCost,cst);
            dfs(v,dest,maxCost);
        }
    }
}

int bin_search(int u, int v){
    int s=lo;
    int t=hi;
    int ans=INT_MAX;

    while(s<=t){
        int mid=(s+t)>>1;
        flag=0;
        visited.reset();
        mostCost=finalCost=0;

        dfs(u,v,mid);

        if(flag){
            ans=min(ans,finalCost);
            t=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int n,m,q,t=0;
    while(~scanf("%d %d %d",&n,&m,&q)){

        if(!n and !m and !q) break;

        //clear graph
        for(int i=0; i<=n; ++i) g[i].clear(), cost[i].clear();

        //scanning graph
        hi=0,lo=INT_MAX;
        for(int i=0; i<m; ++i){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);

            hi=max(hi,w);
            lo=min(lo,w);

            g[u].push_back(v);
            g[v].push_back(u);

            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        //process
        if(t) printf("\n");
        printf("Case #%d",++t);
        for(int i=0; i<q; ++i){
            int u,v;
            scanf("%d %d",&u,&v);

            int ans=bin_search(u,v);

            if(ans==INT_MAX) printf("\nno path");
            else printf("\n%d",ans);
        }
        printf("\n");
    }

    return 0;
}
