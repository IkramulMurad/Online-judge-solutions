#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> II;

priority_queue<II> pqb;
int n;
const int mx=105;
vector<vector<int> > g(mx),c(mx);

void clr(){
    for(int i=0; i<mx; ++i){
        g[i].clear();
        c[i].clear();
    }
}

void scan(){
    scanf("%d",&n);

    int u,v,w;
    while(scanf("%d %d %d",&u,&v,&w) and (u or v or w)){
        g[u].push_back(v);
        g[v].push_back(u);

        c[u].push_back(w);
        c[v].push_back(w);
    }
}

int primsa(){
    int ans=0,total=0;
    bitset<mx> visited;

    priority_queue<II,vector<II>,greater<II> > pq;
    pq.push(make_pair(0,0));

    while(!pq.empty()){
        int node=pq.top().second;
        int cost=pq.top().first;
        pq.pop();

        if(!visited[node]){
            visited[node]=1;
            ans+=cost;
            ++total;
            if(total==n+1) break;
        }

        vector<int> v=g[node];
        vector<int> w=c[node];

        for(int i=0; i<v.size(); ++i){
            if(!visited[v[i]]){
                pq.push(make_pair(w[i],v[i]));
            }
        }
    }

    return ans;
}

int primsb(){
    int ans=0,total=0;
    bitset<mx> visited;

    priority_queue<II> pq;
    pq.push(make_pair(0,0));

    while(!pq.empty()){
        int node=pq.top().second;
        int cost=pq.top().first;
        pq.pop();

        if(!visited[node]){
            visited[node]=1;
            ans+=cost;
            ++total;
            if(total==n+1) break;
        }

        vector<int> v=g[node];
        vector<int> w=c[node];

        for(int i=0; i<v.size(); ++i){
            if(!visited[v[i]]){
                pq.push(make_pair(w[i],v[i]));
            }
        }
    }

    return ans;
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; ++t){
        //clear
        clr();
        //scan
        scan();

        //process
        int ans=0;
        ans+=primsa();
        ans+=primsb();

        //print
        printf("Case %d: ",t);
        if(ans&1) printf("%d/%d\n",ans,2);
        else printf("%d\n",ans/2);

    }

    return 0;
}
