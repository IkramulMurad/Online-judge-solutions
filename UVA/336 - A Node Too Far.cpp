#include <bits/stdc++.h>

using namespace std;

map<int, vector<int> > g;
map<int, bool> visited;
int kount;

void bfs(int node, int ttl){
    queue<pair<int,int> > q;
    q.push(make_pair(node,ttl));

    visited[node]=1;
    ++kount;

    while(!q.empty()){
        /*for(auto it=visited.begin(); it!=visited.end(); ++it){
            cerr<<it->first<<" "<<it->second<<endl;
        }*/
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        vector<int> v=g[x];
        for(int i=0; i<v.size(); ++i){
            int adj=v[i];
            if(!visited[adj] and y>0){
                visited[adj]=1;
                ++kount;
                q.push(make_pair(adj,y-1));
            }
        }

    }
}

int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int n,c=1;
    while(cin>>n and n){
        //clear graph
        g.clear();
        visited.clear();
        //scanning graph
        for(int i=0; i<n; ++i){
            int u,v;
            cin>>u>>v;

            visited[u]=visited[v]=0;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        //process
        int node,ttl,total=g.size();
        while(cin>>node>>ttl){
            if(node==0 and ttl==0) break;

            for(auto it=visited.begin(); it!=visited.end(); ++it){
                it->second=0;
            }

            /*for(auto it=visited.begin(); it!=visited.end(); ++it){
                cerr<<it->first<<" "<<it->second<<endl;
            }*/

            int ans;
            int sz=g.size();
            if(g.find(node)==g.end()) ans=sz;
            else{
                kount=0;
                bfs(node,ttl);
                ans=sz-kount;
            }
            if(ttl<0) ++ans;

            cout<<"Case "<< c++ <<": "<<ans;
            cout<<" nodes not reachable from node ";
            cout<<node<<" with TTL = "<<ttl<<"."<<endl;
        }
    }

    return 0;
}
