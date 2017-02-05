#include <bits/stdc++.h>

using namespace std;

int solve(){
    int n,p,q;
    cin>>n>>p>>q;

    ++p; ++q;

    set<int> s;
    int x,fake[n*n+1];
    fill(fake,fake+(n*n)+1,0);

    for(int i=1; i<=p; ++i){
        cin>>x;
        fake[x]=i;
    }
    for(int i=1; i<=q; ++i){
        cin>>x;
        if(fake[x]){
            s.insert(fake[x]);
            auto it=s.upper_bound(fake[x]);
            if(it!=s.end()) s.erase(it);
        }
    }

    return s.size();
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; ++t){
        int ans=solve();
        printf("Case %d: %d\n",t,ans);
    }

    return 0;
}
