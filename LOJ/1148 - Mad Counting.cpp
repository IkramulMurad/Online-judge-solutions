#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0; i<n; ++i){
            scanf("%d",a+i);
        }
        sort(a,a+n);
        long long ans=0;
        for(int i=0; i<n; ++i){
            int x=a[i];
            int kount=0;
            while(a[i]==x){
                ++kount;
                ++i;
                if(i==n) break;
            }
            int z=kount/(x+1);
            ans+=(z*(x+1));
            if(kount%(x+1))
                ans+=(x+1);
            --i;
        }
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
