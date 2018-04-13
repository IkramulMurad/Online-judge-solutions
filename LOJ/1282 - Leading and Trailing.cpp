#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1000;

int bigMod(int n, int k){
    if(!k) return 1;
    if(k & 1) return ((n % mod) * bigMod(n, k - 1)) % mod;
    return (bigMod(n, k >> 1) * bigMod(n, k >> 1)) % mod;
}

int last3(int n, int k){
    return bigMod(n, k);
}

int first3(LL n, LL k){
    double x = k * log10(n);
    return int(pow(10, x - LL(x)) * 100);
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n, k;
        scanf("%d %d", &n, &k);

        printf("Case %d: %d %03d\n", t, first3(n, k), last3(n, k));
    }

    return 0;
}
