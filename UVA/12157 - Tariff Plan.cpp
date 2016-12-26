#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; ++t){
        int x,n,mile,juice;
        mile=juice=0;

        cin>>n;
        for(int i=0; i<n; ++i){
            cin>>x;
            ++x;
            mile+=(x/30)*10+ bool(x%30)*10;
            juice+=(x/60)*15+ bool(x%60)*15;
        }

        printf("Case %d: ",t);
        if(mile<juice) printf("Mile %d\n",mile);
        else if(juice<mile) printf("Juice %d\n",juice);
        else printf("Mile Juice %d\n",mile);
    }
    return 0;
}
