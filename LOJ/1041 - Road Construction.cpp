#include <bits/stdc++.h>

using namespace std;

typedef pair<int,string> IS;
map<string,vector<string> > g;
map<string,vector<int> > c;
map<string,bool> visited;
int n;

void clr(){
    g.clear();
    c.clear();
    visited.clear();
}

void scan(){
    scanf("%d",&n);
    for(int i=0; i<n; ++i){
        string u,v;
        int w;
        cin>>u>>v>>w;
        visited[u]=visited[v]=0;

        g[u].push_back(v);
        g[v].push_back(u);

        c[u].push_back(w);
        c[v].push_back(w);
    }
}

int prims(){
    int ans=0;
    string source=g.begin()->first;

    priority_queue<IS,vector<IS>,greater<IS> > pq;
    pq.push(make_pair(0,source));

    while(!pq.empty()){
        string node=pq.top().second;
        int cost=pq.top().first;
        pq.pop();

        if(!visited[node]){
            visited[node]=1;
            ans+=cost;
        }

        vector<string> v=g[node];
        vector<int> w=c[node];

        for(int i=0; i<v.size(); ++i){
            if(!visited[v[i]]){
                pq.push(make_pair(w[i],v[i]));
            }
        }
    }

    return ans;
}

void notVisited(int& ans){
    map<string,bool>::iterator it;
    for(it=visited.begin(); it!=visited.end(); ++it){
        if(!it->second){
            ans=-1;
            return;
        }
    }
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; ++t){
        clr();
        scan();

        int ans=prims();
        notVisited(ans);

        printf("Case %d: ",t);
        if(ans==-1) printf("Impossible\n");
        else printf("%d\n",ans);
    }

    return 0;
}
