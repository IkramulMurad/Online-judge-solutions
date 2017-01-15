#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        double ans,r,rect,cir,pi=2*acos(0);
        scanf("%lf",&r);
        rect=4*r*r;
        cir=pi*r*r;
        ans=rect-cir;
        printf("Case %d: %.2f\n",i,ans);
    }
    return 0;
}
