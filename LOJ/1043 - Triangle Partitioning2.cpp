#include <bits/stdc++.h>
 
using namespace std;
 
double getAD(double ade, double a,double b,double c){
    double l=0,h=a,mid=(l+h)/2;
    double ad=mid;
    double de=b*ad/a;
    double ae=c*de/b;
    double p=(ad+de+ae)/2;
    double A=sqrt(p*(p-ad)*(p-de)*(p-ae));
    double EPS=0.0000001;
 
    while(abs(A-ade)>EPS){
        if(A>ade){
            h=mid;
            ad=mid=(l+h)/2;
            de=b*ad/a;
            ae=c*de/b;
            p=(ad+de+ae)/2;
            A=sqrt(p*(p-ad)*(p-de)*(p-ae));
        }
        else{
            l=mid;
            ad=mid=(l+h)/2;
            de=b*ad/a;
            ae=c*de/b;
            p=(ad+de+ae)/2;
            A=sqrt(p*(p-ad)*(p-de)*(p-ae));
        }
    }
    return ad;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        double a,b,c,r;
        scanf("%lf %lf %lf %lf",&a,&b,&c,&r);
        double p=(a+b+c)/2;
        double A=sqrt(p*(p-a)*(p-b)*(p-c));
        double bdec=A/(r+1);
        double ade=A-bdec;
        double ans=getAD(ade,a,c,b);
        printf("Case %d: %.10f\n",t,ans);
    }
    return 0;
}
