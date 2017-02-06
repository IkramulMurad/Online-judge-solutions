#include <bits/stdc++.h>

using namespace std;

map<string,vector<string> > g;
map<string,bool> visited;

string u,v;

void bfs(){
    map<string,string> prv;
    prv[u]="";
    visited[u]=1;

    queue<string> q;
    q.push(u);

    bool flag=true;

    while(!q.empty()){
        string node=q.front();
        q.pop();

        if(node==v){
            flag=false;
            break;
        }
        vector<string> v=g[node];
        for(int i=0; i<v.size(); ++i){
            if(!visited[v[i]]){
                visited[v[i]]=1;
                q.push(v[i]);
                prv[v[i]]=node;
            }
        }
    }

    if(flag){
        cout<<"No route"<<endl;
        return;
    }

    string x=v;
    vector<string> ans;
    while(true){
        ans.push_back(x);
        x=prv[x];
        if(x=="") break;
    }

    for(int i=ans.size()-1; i>0; --i){
        cout<<ans[i]<<" "<<ans[i-1]<<endl;
    }
}

int main()
{
    int n,t=0;

    while(cin>>n){
        g.clear();
        visited.clear();

        for(int i=0; i<n; ++i){
            string s,t;
            cin>>s>>t;

            g[s].push_back(t);
            g[t].push_back(s);
        }

        cin>>u>>v;

        if(t) cout<<endl;
        ++t;

        bfs();
    }

    return 0;
}
