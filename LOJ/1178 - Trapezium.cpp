#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        double a,b,c,d;
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        double e=abs(c-a);
        double p=(b+d+e)/2;
        double A=sqrt(p*(p-b)*(p-d)*(p-e));
        double h=A*2/e;
        double ans=(a+c)*h/2;
        printf("Case %d: %.10f\n",t,ans);
    }
    return 0;
}
