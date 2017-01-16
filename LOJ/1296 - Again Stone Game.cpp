#include <bits/stdc++.h>
 
using namespace std;
 
int calculate_grundy(int x){
    if(x==0 or x==1) return 0;
    if(!(x&1)) return x/2;
    if(ceil(log2(x+1))==floor(log2(x+1))) return 0;
    while(x&1){
        x>>=1;
    }
    return x>>1;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int n;
        long long ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            int x;
            scanf("%d",&x);
            ans^=calculate_grundy(x);
        }
        if(ans)printf("Case %d: Alice\n",t);
        else printf("Case %d: Bob\n",t);
 
    }
    return 0;
}
