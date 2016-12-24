#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;

        int ans=1;
        ans*=n/3;
        ans*=m/3;

        cout<<ans<<endl;
    }
    return 0;
}
