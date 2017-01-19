#include <bits/stdc++.h>
 
using namespace std;
 
const int maxi=5e4+5;
 
vector<vector<int> > g(maxi);
 
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int a[n+1];
        set<pair<int,int> > s;
        for(int i=1; i<=n; ++i){
            int x;
            cin>>x;
            a[i]=x;
            s.insert(make_pair(x,i));
        }
 
        //clear
        for(int i=0; i<=n; ++i)  g[i].clear();
        //input
        for(int i=1; i<n; ++i){
            int x,y;
            cin>>x>>y;
 
            g[x].push_back(y);
            g[y].push_back(x);
        }
 
        if(n==1){
            cout<<0<<endl;
            continue;
        }
 
        for(int i=1; i<=n; ++i){
            vector<int> t=g[i];
 
            s.erase(make_pair(a[i],i));
            for(int j=0; j<t.size(); ++j){
                pair<int,int> node=make_pair(a[t[j]],t[j]);
                s.erase(node);
            }
            if(i!=1) cout<<" ";
            if(s.empty()) cout<<0;
            else{
                auto it=s.rbegin();
                cout<<it->second;
            }
 
            s.insert(make_pair(a[i],i));
            for(int j=0; j<t.size(); ++j){
                pair<int,int> node=make_pair(a[t[j]],t[j]);
                s.insert(node);
            }
        }
        cout<<endl;
 
    }
    return 0;
}
