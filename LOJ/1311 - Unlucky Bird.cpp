#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        double v1,v2,v3,a1,a2,t,s1,s2,s,d;
        cin>>v1>>v2>>v3>>a1>>a2;
        s1=v1*v1/(2*a1);
        s2=v2*v2/(2*a2);
        s=s1+s2;
        t=v1/a1;
        if(v2/a2>t) t=v2/a2;
        d=v3*t;
        printf("Case %d: %.10f %.10f\n",i,s,d);
    }
    return 0;
}
