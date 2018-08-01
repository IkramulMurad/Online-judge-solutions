#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;

LL bigmod(LL b, LL p, LL mod){
    if(p == 0) return 1;
    if(p & 1) return ((b % mod) * bigmod(b, p - 1, mod)) % mod;
    return (bigmod(b, p / 2, mod) * bigmod(b, p / 2, mod)) % mod;
}

LL sumUpToN(LL n){
    LL ans = (n % mod * (n + 1) % mod) % mod;
    ans = (ans * bigmod(2, mod - 2, mod)) % mod;
    return ans;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        LL n, a, b, l;
        cin >> n >> a >> b >> l;

        LL sOrientaion1 = ((b - a) % mod * (l - b) % mod) % mod;
        LL sOrientaion2 = sumUpToN(l - (b + 1));
        LL sOrientaion = (sOrientaion1 + sOrientaion2) % mod;
        LL othersOrientation = bigmod(n - 1, l - 3, mod);

        LL ans = (sOrientaion * othersOrientation) % mod;
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
