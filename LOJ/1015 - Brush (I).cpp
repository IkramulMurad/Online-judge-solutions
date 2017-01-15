#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long sum;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        sum=0;
        for(int j=0;j<n;j++){
            int x;
            scanf("%d",&x);
            if(x>=0) sum+=x;
        }
        printf("Case %d: %lld\n",i,sum);
    }
    return 0;
}
