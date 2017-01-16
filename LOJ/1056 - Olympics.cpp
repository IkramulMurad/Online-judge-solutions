#include <bits/stdc++.h>
 
using namespace std;
 
#define pi acos(-1)
 
double f(double a,double b){
    double d=hypot(a,b);
    double r=d/2;
    double theta=2*asin(b/d);
    return r*theta;
}
 
double solve(int a,int b){
    double h=200,l=0,len,wid,farc,arc;
    double eps=0.0000001;
 
    do{
        len=(h+l)/2;
        wid=(len*b)/a;
        farc=f(len,wid);
        arc=200.0-len;
        if(abs(farc-arc)<=eps){
            return len;
        }
        else if(farc<arc){
            l=len;
        }
        else{
            h=len;
        }
 
    }while(h>=l);
    return len;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int a,b;
        scanf("%d",&a);
        getchar();
        getchar();
        scanf("%d",&b);
        double l=solve(a,b);
        double w=(l*b)/a;
        printf("Case %d: %.10f %.10f\n",t,l,w);
    }
    return 0;
}
