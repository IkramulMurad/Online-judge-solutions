#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; ++t){
        int n,d;
        scanf("%d %d",&n,&d);

        LL a[n];
        for(int i=0; i<n; ++i) scanf("%lld",a+i);

        deque<LL> dqmx,dqmn;

        //preparing deque
        for(int i=0; i<d; ++i){
            //max
            while(!dqmx.empty() and a[i]>=a[dqmx.back()]){
                dqmx.pop_back();
            }
            dqmx.push_back(i);

            //Min
            while(!dqmn.empty() and a[i]<=a[dqmn.back()]){
                dqmn.pop_back();
            }
            dqmn.push_back(i);
        }

        //process
        LL mx=0;
        for(int i=d; i<n; ++i){
            mx=max(mx, a[dqmx.front()]-a[dqmn.front()]);

            //max
            while(!dqmx.empty() and dqmx.front()<=i-d){
                dqmx.pop_front();
            }
            while(!dqmx.empty() and a[i]>=a[dqmx.back()]){
                dqmx.pop_back();
            }
            dqmx.push_back(i);

            //min
            while(!dqmn.empty() and dqmn.front()<=i-d){
                dqmn.pop_front();
            }
            while(!dqmn.empty() and a[i]<=a[dqmn.back()]){
                dqmn.pop_back();
            }
            dqmn.push_back(i);
        }
        mx=max(mx, a[dqmx.front()]-a[dqmn.front()]);

        //print
        printf("Case %d: %lld\n",t,mx);
    }

    return 0;
}
