#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; ++t){
        int n;
        cin>>n;

        int a[n];
        for(int i=0; i<n; ++i) cin>>a[i];

        sort(a,a+n);

        int ans=a[n-1];
        for(int i=1; i<n-1; ++i){
            if(a[i-1]+1!=a[i]){
                ans=a[i-1];
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
