#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int ox,oy,ax,ay,bx,by;
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        double ans,theta,x,m1,m2,pi=2*acos(0),r,d;
        
        r=sqrt(pow(ax-ox,2)+pow(ay-oy,2));
        d=sqrt(pow(ax-bx,2)+pow(ay-by,2));
        x=(2*r*r-d*d)/(2*r*r);
        theta=acos(x);
        theta*=(180/pi);
        theta=min(theta,(double)(360-theta));
        ans=2*pi*r*(theta/360);
        cout<<fixed<<setprecision(10)<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}
