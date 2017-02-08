#include <bits/stdc++.h>

using namespace std;

typedef pair<int,string> ps;

map<string, vector<string> > g;
map<string, vector<int> > c;

int prims(string s, string t){
    int ans=1e9;
    map<string,bool> taken;

    priority_queue<ps> pq;
    pq.push(make_pair(1e9,s));

    while(!pq.empty()){
        string node=pq.top().second;
        int cost=pq.top().first;

        pq.pop();

        if(!taken[node]){
            ans=min(ans,cost);
            taken[node]=1;

            if(node==t) return ans;
        }

        vector<string> v=g[node];
        vector<int> w=c[node];

        for(int i=0; i<v.size(); ++i){
            if(!taken[v[i]]){
                pq.push(make_pair(w[i],v[i]));
            }
        }
    }

    return ans;
}

int main()
{
    int n,m,tc=1;

    while(cin>>n>>m and (n or m)){
        g.clear();
        c.clear();

        for(int i=0; i<m; ++i){
            string u,v;
            int w;
            cin>>u>>v>>w;

            g[u].push_back(v);
            g[v].push_back(u);

            c[u].push_back(w);
            c[v].push_back(w);
        }

        string s,t;
        cin>>s>>t;

        int ans=prims(s,t);
        printf("Scenario #%d\n",tc++);
        printf("%d tons\n\n",ans);
    }

    return 0;
}
