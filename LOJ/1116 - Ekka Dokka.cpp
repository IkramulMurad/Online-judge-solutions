#include <bits/stdc++.h>
 
using namespace std;
long long n,m;
long long getM(long long w){
    long long m=1;
    while(!(w&1)){
        m*=2;
        w/=2;
    }
    return m;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        long long w;
        scanf("%lld",&w);
        if(w%2){
            printf("Case %d: Impossible\n",i);
        }
        else{
            long long n,m;
            m=getM(w);
            n=w/m;
            printf("Case %d: %lld %lld\n",i,n,m);
        }
    }
    return 0;
}
