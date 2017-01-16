#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long LL;
LL ret;
 
bool binSearch(LL q){
    LL hi=1LL<<63,lo=0,mid;
    bool flag=0;
    while(hi>=lo){
        mid=(hi+lo)>>1;
        LL f=0;
        LL den=5;
        while(mid>=den){
            LL res=mid/den;
            f+=res;
            den*=5;
            if(f>q) break;
        }
        if(f==q){
            ret=mid-mid%5;
            return 1;
        }
        else if(f>q) hi=mid-1;
        else lo=mid+1;
    }
    return flag;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        LL q;
        scanf("%lld",&q);
        if(binSearch(q)){
            printf("Case %d: %lld\n",t,ret);
        }
        else printf("Case %d: impossible\n",t);
    }
    return 0;
}
