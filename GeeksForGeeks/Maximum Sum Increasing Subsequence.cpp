#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; ++i) cin>>a[i];

    int msis[n];
    for(int i=0; i<n; ++i) msis[i]=a[i];

    for(int i=1; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(a[j]<a[i]){
                msis[i]=max(msis[i],a[i]+msis[j]);
            }
        }
    }

    /*for(int i=0; i<n; ++i) cerr<<msis[i]<<" ";
    cerr<<endl;*/

    int ans=*max_element(msis,msis+n);
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
