#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);

        LL a,b,c,ans=0;
        for(int i=0; i<n; ++i){
            scanf("%lld %lld %lld",&a,&b,&c);
            ans+=a*c;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
