#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=1e6+5;
int two[mx],five[mx];
 
void getFactors(){
    two[0]=five[0]=0;
    for(int i=1;i<mx-2;++i){
        int x=i;
        int kount2=0,kount5=0;
        while(!(x&1)){
            x>>=1;
            ++kount2;
        }
        while(x%5==0){
            x/=5;
            ++kount5;
        }
        two[i]=two[i-1]+kount2;
        five[i]=five[i-1]+kount5;
    }
}
 
 
int main()
{
    getFactors();
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int n,r,p,q;
        scanf("%d %d %d %d",&n,&r,&p,&q);
        int n2,n5,r2,r5,nr2,nr5,pq2,pq5;
        n2=two[n]; n5=five[n];
        r2=two[r]; r5=five[r];
        nr2=two[n-r]; nr5=five[n-r];
        pq2=(two[p]-two[p-1])*q;
        pq5=(five[p]-five[p-1])*q;
        int ans,ans2,ans5;
        ans2=n2+pq2-r2-nr2;
        ans5=n5+pq5-r5-nr5;
        ans=min(ans2,ans5);
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
