#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; ++i) cin>>a[i];

    int lis[n];
    fill(lis,lis+n,1);

    for(int i=1; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(a[j]<a[i]){
                lis[i]=max(lis[i],1+lis[j]);
            }
        }
    }

    int ans=*max_element(lis,lis+n);
    cout<<ans<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
