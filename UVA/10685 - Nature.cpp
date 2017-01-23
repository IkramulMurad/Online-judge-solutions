#include <bits/stdc++.h>

using namespace std;

const int mx=5000+5;
int val;

map<string, vector<string> > g;
map<string, bool> visited;

void dfs(string node){
    visited[node]=1;
    val++;

    vector<string> v=g[node];
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs(v[i]);
        }
    }
}

int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int n,m;
    while(cin>>n>>m){
        if(n==0 and m==0) break;
        //clear graph
        g.clear();
        visited.clear();

        //scanning graph
        string s[n];
        for(int i=0; i<n; ++i){
            cin>>s[i];
            visited[s[i]]=false;
        }

        for(int i=0; i<m; ++i){
            string u,v;
            cin>>u>>v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        //process
        int ans=0;
        for(int i=0; i<n; ++i){
            if(!visited[s[i]]){
                val=0;
                dfs(s[i]);
                ans=max(ans,val);
            }
        }

        cout<<ans<<endl;

    }

    return 0;
}
