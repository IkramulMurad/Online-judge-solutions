#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        double ra,rb,rc;
        cin>>ra>>rb>>rc;
        double pi=2*acos(0),theta,thetb,thetc,a,b,c,p,Area;
        a=ra+rb; b=rb+rc; c=rc+ra;
        p=(a+b+c)/2;
        Area=sqrt(p*(p-a)*(p-b)*(p-c));
        theta=acos((b*b+c*c-a*a)/(2*b*c));
        thetb=acos((a*a+c*c-b*b)/(2*a*c));
        thetc=acos((b*b+a*a-c*c)/(2*b*a));
        double aa,ab,ac;
        aa=ra*ra*thetb/2;
        ab=rb*rb*thetc/2;
        ac=rc*rc*theta/2;
        Area=Area-aa-ab-ac;
        printf("Case %d: %.10f\n",i,Area);
    }
    return 0;
}
