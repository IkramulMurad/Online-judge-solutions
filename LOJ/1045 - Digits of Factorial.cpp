#include <bits/stdc++.h>
 
using namespace std;

double logTable[1000001];
int main()
{
    int t;
    scanf("%d",&t);
    logTable[0]=0;
    for(int i=1;i<=1000000;i++){
        logTable[i]=log(i)+logTable[i-1];
    }
    for(int i=1;i<=t;i++){
        int n,b;
        scanf("%d %d",&n,&b);
        double ans=0;
        ans=logTable[n]/log(b);
        int res=ceil(ans);
        if(n==0) res=1;
        printf("Case %d: %d\n",i,res);
    }
    return 0;
}
