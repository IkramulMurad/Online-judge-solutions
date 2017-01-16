#include <bits/stdc++.h>
 
using namespace std;
 
#define PI acos(-1.0)
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        double x,y,c;
        scanf("%lf %lf %lf",&x,&y,&c);
 
        double hi=y,lo=0,mid;
        double base,A,C,p,A2,C2,q,fc;
        double EPS=0.0000001;
 
        do{
            mid=(hi+lo)/2;
            base=mid;
            A=asin(base*sin(PI/2)/x);
            C=(PI/2)-A;
            p=base*(sin(C)/sin(A));
            A2=asin(base*sin(PI/2)/y);
            C2=(PI/2)-A2;
            q=base*(sin(C2)/sin(A2));
            fc=(p*q)/(p+q);
            if(c>fc){
                hi=mid;
            }
            else{
                lo=mid;
            }
        }while(abs(fc-c)>EPS);
 
        printf("Case %d: %.10f\n",t,base);
    }
    return 0;
}
