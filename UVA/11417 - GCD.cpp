#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n)){
        if(!n) break;
        int g=0;
        for(int i=1; i<n; ++i){
            for(int j=i+1; j<=n; ++j){
                g+=__gcd(i,j);
            }
        }
        printf("%d\n",g);
    }
    return 0;
}
