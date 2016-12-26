#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; ++t){
        int prv,x,n,hi,lo;
        hi=lo=0;
        cin>>n>>prv;

        for(int i=1; i<n; ++i){
            cin>>x;
            if(x>prv) ++hi;
            else if(x<prv) ++lo;
            prv=x;
        }

        printf("Case %d: %d %d\n",t,hi,lo);
    }
    return 0;
}
