#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL inf=1e18;
int x[]={1,1,-1,-1};
int y[]={1,-1,1,-1};


int main()
{
    int tc;
    cin>>tc;

    for(int t=0; t<tc; ++t){
        LL n,k,da,db;
        cin>>n>>k>>da>>db;

        LL a,b,c,need=inf;
        for(int i=0; i<4; ++i){
            b=(k+x[i]*da+y[i]*db)/3;
            a=b+x[i]*-1*da;
            c=b+y[i]*-1*db;

            LL mx=max(max(a,b),c);
            if(a+b+c==k and a>=0 and b>=0 and c>=0){
                need=min(need,mx-a+mx-b+mx-c);
            }
        }

        LL dif=n-k;
        dif-=need;
        if(dif<0 or dif%3) cout<<"no"<<endl;
        else cout<<"yes"<<endl;

    }

    return 0;
}
