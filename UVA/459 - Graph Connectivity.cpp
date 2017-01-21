#include <bits/stdc++.h>

using namespace std;

const int mx=100;

vector<vector<int> > g(mx);
bitset<mx> visited;

void dfs(int node){
    visited[node]=1;

    vector<int> v=g[node];
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

    int tc,t=0;
    cin>>tc;

    while(tc--){
        //clear graph
        for(int i=0; i<mx; ++i) g[i].clear();
        visited.reset();

        string s;
        cin>>s;
        getchar();

        int n=s[0]-'A';

        while(getline(cin,s) and s!=""){

            int u,v;
            u=s[0]-'A';
            v=s[1]-'A';

            g[u].push_back(v);
            g[v].push_back(u);
        }

        int kount=0;

        for(int i=0; i<=n; ++i){
            if(!visited[i]){
                kount++;
                dfs(i);
            }
        }
        if(t++) cout<<endl;
        cout<<kount<<endl;
    }

    return 0;
}
