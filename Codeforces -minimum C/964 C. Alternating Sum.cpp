#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 9;
string s;

LL bigMod(LL b, LL p){
    if(p == 0) return 1;
    if(p & 1) return (b * bigMod(b, p - 1)) % mod;
    return (bigMod(b, p >> 1) * bigMod(b, p >> 1)) % mod;
}

LL inverseMod(LL a){
    return bigMod(a, mod - 2);
}

LL getR(LL a, LL b, LL k){
    LL bByA = (b * inverseMod(a)) % mod;
    return bigMod(bByA, k);
}

LL getA(LL a, LL b, LL n, LL k){
    LL ans = 0;
    for(int i = 0; i < k; ++i){
        LL part= (bigMod(a, n - i) * bigMod(b, i)) % mod;

        if(s[i] == '+') ans = (ans + part) % mod;
        else ans = (ans - part + mod) % mod;
    }
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    LL n, a, b, k;
    cin >> n >> a >> b >> k >> s;

    LL A = getA(a, b, n, k);
    LL R = getR(a, b, k);

    LL p = (n + 1) / k;
    LL ans = 0;

    if(R == 1){
        ans = (p * A) % mod;
    }
    else{
        LL oneMinusRn = (1 - bigMod(R, p) + mod) % mod;
        LL oneMinusR = (1 - R + mod) % mod;

        ans = (A * oneMinusRn) % mod;
        ans = (ans * inverseMod(oneMinusR)) % mod;
    }

    cout << ans << endl;

    return 0;
}
