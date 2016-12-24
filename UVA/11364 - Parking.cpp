#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int n,x,mn=100,mx=0;
        cin>>n;
        //street is numbered as
        //1,2,3,...13...24...37...89...99
        for(int i=0; i<n; ++i){
            cin>>x;
            mn=min(mn,x);
            mx=max(mx,x);
        }
        cout<<(mx-mn)*2<<endl;
    }
    return 0;
}
