#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        double x,y,z,pi=2*acos(0);
        x=double(a*a+b*b-c*c)/double(2*a*b);
        y=double(c*c+b*b-a*a)/double(2*c*b);
        z=double(a*a+c*c-b*b)/double(2*a*c);
        x=acos(x)*180/pi;
        y=acos(y)*180/pi;
        z=acos(z)*180/pi;
        if(x==90||y==90||z==90){
            printf("Case %d: yes\n",i);
        }
        else printf("Case %d: no\n",i);
    }
    return 0;
}
