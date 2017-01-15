#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        long long ans,l,r;
        long long left,right;
        scanf("%lld %lld",&l,&r);
        if((r-l)<=3){
            ans=0;
            for(long long k=l;k<=r;k++){
                long long z=((k*(k+1))/2);
                if(z%3==0) ans++;
            }
        }
        else{
            ans=(r-l)-(r-l)/3;
            left=((l*(l+1))/2)%3;
            right=((r*(r+1))/2)%3;
            if(left==0&&right==0) {
                if((r-l)%3!=2)ans++;
            }
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
