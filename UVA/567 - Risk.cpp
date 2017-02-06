#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g(22);

void clr(){
    for(int i=0; i<22; ++i) g[i].clear();
}

int bfs(int u, int v){
    //should return distance
    bitset<25> visited;
    visited[u]=1;

    queue<pair<int,int> > q;
    q.push(make_pair(u,0));

    while(!q.empty()){
        int node=q.front().first;
        int val=q.front().second;
        q.pop();

        if(node==v) return val;

        vector<int> vv=g[node];
        for(int i=0; i<vv.size(); ++i){
            if(!visited[vv[i]]){
                visited[vv[i]]=1;
                q.push(make_pair(vv[i],val+1));
            }
        }
    }

    return 1;
}

int main()
{
    int t=0;
    int x;
    while(cin>>x){
        clr();
        //first line
        for(int i=0; i<x; ++i){
            int v;
            cin>>v;
            g[1].push_back(v);
            g[v].push_back(1);
        }

        //rest 18 lines
        for(int i=2; i<=19; ++i){
            int n;
            cin>>n;
            for(int j=0; j<n; ++j){
                int v;
                cin>>v;
                g[i].push_back(v);
                g[v].push_back(i);
            }
        }

        int q;
        cin>>q;

        printf("Test Set #%d\n",++t);
        for(int i=0; i<q; ++i){
            int u,v;
            cin>>u>>v;

            int ans=bfs(u,v);
            printf("%2d to %2d: %d\n",u,v,ans);
        }
        printf("\n");
    }
    return 0;
}
