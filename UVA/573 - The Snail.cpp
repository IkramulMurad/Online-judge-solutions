#include <bits/stdc++.h>

using namespace std;

int main()
{
    double h,u,d,f;
    while(cin>>h>>u>>d>>f and h){
        double initial,dayClimbed,dayBest,dayFinal;
        initial=dayClimbed=dayBest=dayFinal=0;
        double fatigue=u*f/100;
        int i=0,flag=0;
        for(; ; ++i){
            dayClimbed=max(u,0.0);  //non negative distance
            dayBest=initial+dayClimbed;
            dayFinal=dayBest-d;
            initial=dayFinal;
            u-=fatigue;
            
            if(dayFinal<0){
                flag=1;
                break;
            }
            if(dayBest>h) break;
        }
        if(flag) printf("failure on day %d\n",i+1);
        else printf("success on day %d\n",i+1);
    }
    return 0;
}
