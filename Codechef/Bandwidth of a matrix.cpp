#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; ++t){
        int n;
        cin>>n;

        int kount=0;
        for(int i=0; i<n*n; ++i){
            int x;
            cin>>x;

            kount+=x;
        }

        int ans=0;
        kount-=n;

        while(kount>0){
            --n;
            kount-=2*n;
            ++ans;
        }

        cout<<ans<<endl;
    }

    return 0;
}
