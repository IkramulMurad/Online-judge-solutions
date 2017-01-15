#include <bits/stdc++.h>
 
using namespace std;
double pi=pi=2*acos(0);
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int ra,rb,h,p;
        scanf("%d %d %d %d",&ra,&rb,&h,&p);
        double vp,theta,rp;
        double val=double(h)/double(ra-rb);
        theta=atan(val);
        rp=(double(p)/tan(theta))+rb;
        vp=pi*p*(rb*rb+rb*rp+rp*rp)/3;
        printf("Case %d: %.8f\n",i,vp);
    }
    return 0;
}
