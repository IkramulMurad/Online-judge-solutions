#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;

    int a[n],fake[n],b[n];

    for(int i=0; i<n; ++i){
        cin>>a[i];
        fake[a[i]]=i+1;
    }

    set<int> s;
    for(int i=0; i<n; ++i){
        cin>>b[i];
        s.insert(fake[b[i]]);

        auto it=s.upper_bound(fake[b[i]]);
        if(it!=s.end()) s.erase(it);
    }

    cout<<s.size()<<endl;

}

int main()
{
    int tc;
    cin>>tc;

    while(tc--){
        solve();
    }

    return 0;
}
