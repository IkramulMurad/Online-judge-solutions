#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        long long n,m,ans;
        scanf("%lld %lld",&n,&m);
        ans=(n/2)*m;
        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}
