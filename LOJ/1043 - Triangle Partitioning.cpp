#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        double ab,ac,bc,rat,p,abc,bdec,ade,de,ad;
        scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&rat);
        p=(ab+bc+ac)/2;
        abc=sqrt(p*(p-ab)*(p-ac)*(p-bc));
        bdec=abc/(1+rat);
        ade=abc-bdec;
        de=bc*sqrt(ade)/sqrt(abc);
        ad=ab*de/bc;
        printf("Case %d: %.10f\n",t,ad);
    }
    return 0;
}
