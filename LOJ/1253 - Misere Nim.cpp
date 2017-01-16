#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int n;
        scanf("%d",&n);
        int a[n];
        int flag=1;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(flag){
                if(a[i]>1) flag=0;
            }
        }
        if(flag){
            if(n&1) printf("Case %d: Bob\n",t);
            else printf("Case %d: Alice\n",t);
        }
        else{
            long long ans=0;
            for(int i=0;i<n;++i){
                ans^=a[i];
            }
            if(ans) printf("Case %d: Alice\n",t);
            else printf("Case %d: Bob\n",t);
        }
    }
    return 0;
}
