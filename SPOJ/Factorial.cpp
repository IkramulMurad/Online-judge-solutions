#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int trailing_zero(LL n){
    int ans=0;
    LL x=5;
    
    while(x<=n){
        ans+=n/x;
        x*=5;
    }
    
    return ans;
}

int main()
{
    int tc;
    cin>>tc;
    
    for(int t=0; t<tc; ++t){
        int n;
        cin>>n;
        
        cout<<trailing_zero(n)<<endl;
    }
    
    return 0;
}
