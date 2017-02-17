#include <bits/stdc++.h>

using namespace std;

const double pi=acos(-1);

double radian(double angle){
    return angle*pi/180;
}

int main()
{
    int l,w,h,angle;

    cerr<<pi<<endl;

    while(cin>>l>>w>>h>>angle){
        double theta=radian(angle);
        double full=l*w*h;

        double adjacent=l;
        double opposite=l*tan(theta);
        double ans=full-(w*adjacent*opposite/2);

        if(opposite>h){
            opposite=h;
            adjacent=opposite*cos(theta)/sin(theta);
            ans=w*adjacent*opposite/2;
        }

        printf("%.3f mL\n",ans);
    }

    return 0;
}
