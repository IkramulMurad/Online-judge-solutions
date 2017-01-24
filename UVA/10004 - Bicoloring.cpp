#include <bits/stdc++.h>

using namespace std;

const int mx=205;
vector<vector<int> > g(mx);
bitset<mx> visited;
int color[mx];

void dfs(int node, int c){
    visited[node]=1;
    color[node]=c;

    vector<int> v=g[node];
    for(int i=0; i<v.size(); ++i){
        if(!visited[v[i]]){
            dfs(v[i],c^1);
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    while(cin>>n and n){

        //clear graph
        for(int i=0; i<n; ++i) g[i].clear();
        visited.reset();
        memset(color,0,sizeof color);

        //scanning graph
        cin>>m;
        for(int i=0; i<m; ++i){
            int u,v;
            cin>>u>>v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        //process
        dfs(0,0);

        bool impossible=false;
        for(int i=0; i<n; ++i){
            vector<int> v=g[i];
            for(int j=0; j<v.size(); ++j){
                if(color[i]==color[v[j]]){
                    impossible=true;
                    break;
                }
            }
        }

        if(impossible) cout<<"NOT BICOLORABLE."<<endl;
        else cout<<"BICOLORABLE."<<endl;
    }

    return 0;
}
