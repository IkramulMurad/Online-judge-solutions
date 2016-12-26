#include <bits/stdc++.h>

using namespace std;

int main()
{
    int months,dep;
    double down,amount;
    while(cin>>months>>down>>amount>>dep){
        if(months<0) break;

        int x;
        double y,p[102];
        for(int i=0; i<dep; ++i){
            scanf("%d %lf",&x,&y);

            for(int j=x; j<101; ++j) p[j]=y;
        }

        int ans=0;
        double eachMonth=amount/months;
        double owe=amount;
        double val=amount+down;
        val=val-(val*p[0]);

        while(owe>val){
            ++ans;
            val-=val*p[ans];
            owe-=eachMonth;
        }

        //for zero, it should be printed months also
        if(ans!=1) cout<<ans<<" months"<<endl;
        else cout<<1<<" month"<<endl;
    }
    return 0;
}
