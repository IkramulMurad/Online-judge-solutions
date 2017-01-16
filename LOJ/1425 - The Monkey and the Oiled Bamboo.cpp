#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int n;
        scanf("%d",&n);
        int x,y=0,a[n];
        for(int i=0; i<n; ++i){
            scanf("%d",&x);
            a[i]=x-y;
            y=x;
        }
        int k=a[n-1];
        for(int i=n-2; i>=0; --i){
            if(a[i]==k) ++k;
            k=max(k,a[i]);
        }
        printf("Case %d: %d\n",t,k);
    }
    return 0;
}
