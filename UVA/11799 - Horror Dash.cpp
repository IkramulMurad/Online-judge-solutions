#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; ++t){
        int n,x,mx=0;
        cin>>n;
        for(int i=0; i<n; ++i){
            cin>>x;
            mx=max(mx,x);
        }
        printf("Case %d: %d\n",t,mx);
    }
    return 0;
}
