#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<vector<int> > VoV;
const int mx=102;
VoV g(mx);
bitset<mx> visited;
int cnt;
 
void bfs(int node, int target){
    if(node==target) return;
    vector<int> old,cur;
    old.push_back(node);
 
    while(!old.empty()){
        ++cnt;
 
        int sz=old.size();
        for(int i=0; i<sz; ++i){
            int x=old[i];
            vector<int> v=g[x];
            for(int j=0; j<v.size(); ++j){
                if(v[j]==target) return;
                if(!visited[v[j]]){
                    visited[v[j]]=1;
                    cur.push_back(v[j]);
                }
            }
        }
        old.clear();
        old=cur;
        cur.clear();
    }
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int n,m,s,d;
        scanf("%d %d",&n,&m);
 
        //clear
        for(int i=0; i<mx; ++i) g[i].clear();
 
        //scanning graph
        int u,v;
        for(int i=0; i<m; ++i){
            scanf("%d %d",&u,&v);
 
            g[u].push_back(v);
            g[v].push_back(u);
        }
 
        scanf("%d %d",&s,&d);
 
        //process
        int ans=0;
        for(int i=0; i<n; ++i){
            int kount=0;
 
            visited.reset();
            cnt=0;
            bfs(s,i);
            kount+=cnt;
 
            visited.reset();
            cnt=0;
            bfs(i,d);
            kount+=cnt;
 
            ans=max(ans,kount);
        }
 
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
