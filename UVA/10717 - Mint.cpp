#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL lcm(LL a, LL b){
    return a/__gcd(a,b)*b;
}

int main()
{
    int n,t;
    while(~scanf("%d %d",&n,&t)){
        if(n==0 and t==0) break;

        int coin[n],table[t];

        for(int i=0; i<n; ++i) scanf("%d",coin+i);
        for(int i=0; i<t; ++i) scanf("%d",table+i);

        for(int i=0; i<t; ++i){
            LL mn,mx;
            mn=LLONG_MAX;
            mx=0;
            for(int j=0; j<n; ++j){
                for(int k=j+1; k<n; ++k){
                    for(int l=k+1; l<n; ++l){
                        for(int m=l+1; m<n; ++m){
                            LL c=lcm(lcm(lcm(coin[m],coin[l]),coin[k]),coin[j]);
                            LL q=table[i]/c;
                            mx=max(mx,c*q);
                            if(table[i]%c) ++q;
                            mn=min(mn,c*q);
                        }
                    }
                }
            }
            printf("%lld %lld\n",mx,mn);
        }
    }
    return 0;
}
