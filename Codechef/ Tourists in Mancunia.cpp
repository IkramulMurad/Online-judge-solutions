#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=1e5+5;
 
bitset<mx> visited;
vector<multiset<int> >g(mx), ans(mx);
 
void dfs(int node){
    visited[node]=1;
 
    for(auto it=g[node].begin(); it!=g[node].end(); ++it){
        int v=*it;
        if(!visited[v]){
            dfs(v);
        }
    }
}
 
bool isEuler(int n){
    dfs(1);
    for(int i=1; i<=n; ++i){
        if(!visited[i]){
            return false;
        }
        if(g[i].size()&1){
            return false;
        }
    }
    return true;
}
 
void EulerTour(vector<int>& circuit){
    int u=1;
    stack<int> stk;
    while(!g[u].empty() or !stk.empty()){
        if(g[u].empty()){
            circuit.push_back(u);
            u=stk.top();
            stk.pop();
        }
        else{
            stk.push(u);
 
            //remove u--v edge
            int v=*g[u].begin();
            auto it=g[u].find(v);
            auto jt=g[v].find(u);
            g[u].erase(it);
            g[v].erase(jt);
            //new current
            u=v;
        }
    }
}
 
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
 
    int n,m;
    while(~scanf("%d %d",&n,&m)){
 
        vector<pair<int,int> >original;
        //clear graph
        for(int i=0; i<=n; ++i) g[i].clear();
        for(int i=0; i<=n; ++i) ans[i].clear();
        visited.reset();
 
        //scanning graph
        for(int i=0; i<m; ++i){
            int u,v;
            scanf("%d %d",&u,&v);
 
            original.push_back(make_pair(u,v));
 
            g[u].insert(v);
            g[v].insert(u);
        }
 
        //process
        if(!isEuler(n) or n>m){
            printf("NO\n");
        }
        else{
            //make path
            vector<int> circuit;
            EulerTour(circuit);
 
            if(circuit.size()){
                circuit.push_back(circuit[0]);
            }
            reverse(circuit.begin(),circuit.end());
 
            //re-arrange graph
            for(int i=1; i<circuit.size(); ++i){
                int u=circuit[i-1];
                int v=circuit[i];
                ans[u].insert(v);
            }
 
            for(int i=0; i<m; ++i){
                int u=original[i].first;
                int v=original[i].second;
 
                if(ans[u].count(v)){
                    auto it=ans[u].find(v);
                    ans[u].erase(it);
                }
                else{
                    int temp=original[i].first;
                    original[i].first=original[i].second;
                    original[i].second=temp;
                }
            }
 
            //printing
            printf("YES");
            for(int i=0; i<m; ++i){
                printf("\n");
                printf("%d %d",original[i].first,original[i].second);
            }
            printf("\n");
        }
    }
 
    return 0;
}
