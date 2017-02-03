#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g(35);

int parent[35];

bool match(vector<int> v, vector<int> t){
    for(int i=0; i<v.size(); ++i){
        if(v[i]>=t[i]) return false;
    }
    return true;
}

void solve(int n, int m){
    //keep boxes in order and sort
    pair<vector<int> , int> pp[n];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            int x;
            cin>>x;
            pp[i].first.push_back(x);
        }
        pp[i].second=i+1;
    }

    for(int i=0; i<n; ++i){
        sort(pp[i].first.begin(),pp[i].first.end());
    }
    sort(pp,pp+n);

    //lis
    int lis[n];
    fill(lis,lis+n,1);
    for(int i=0; i<=30; ++i) parent[i]=i;

    for(int i=1; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(match(pp[j].first,pp[i].first)){
                if(lis[i]<1+lis[j]){
                    lis[i]=1+lis[j];
                    parent[i]=j;
                }
            }
        }
    }

    //find max
    int idx=0;
    int ans=0;
    for(int i=0; i<n; ++i){
        if(lis[i]>ans){
            ans=lis[i];
            idx=i;
        }
    }

    //find path
    vector<int> res;
    while(true){
        res.push_back(pp[idx].second);
        if(parent[idx]==idx) break;
        idx=parent[idx];
    }

    //print ans and path
    cout<<ans<<endl;
    for(int i=res.size()-1; i>=0; --i){
        cout<<res[i];
        if(i) cout<<" ";
    }
    cout<<endl;

}

int main()
{
    int n,m;
    while(cin>>n>>m){
        solve(n,m);
    }
    return 0;
}
