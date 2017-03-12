#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; ++t){
        int n;
        cin>>n;

        int a[n],b[n];
        for(int i=0; i<n; ++i) cin>>a[i];
        for(int i=0; i<n; ++i) cin>>b[i];

        LL ans1,ans2;
        ans1=ans2=0;

        for(int i=0; i<n; ++i){
            if(i&1){
                ans1+=a[i];
                ans2+=b[i];
            }
            else{
                ans1+=b[i];
                ans2+=a[i];
            }
        }

        cout<<min(ans1,ans2)<<endl;
    }

    return 0;
}
