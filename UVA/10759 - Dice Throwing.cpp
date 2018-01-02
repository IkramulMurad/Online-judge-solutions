#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long LL;
LL dp[25][150];
int n, x;

LL power(LL base, LL exp){
    LL res = 1;
    while(exp){
        if(exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

LL cal(int pos, int sum){
    if(pos == n){
        if(sum >= x) return 1;
        return 0;
    }
    if(dp[pos][sum] != -1) return dp[pos][sum];

    LL ret = 0;
    for(int i = 1; i <= 6; ++i){
        ret += cal(pos + 1, sum + i);
    }

    return dp[pos][sum] = ret;
}

int main()
{
    while(cin >> n >> x and (n or x)){
        memset(dp, -1, sizeof(dp));
        LL total = power(6LL, n);
        LL favor = cal(0, 0);

        LL gcd = __gcd(favor, total);
        total /= gcd;   favor /= gcd;

        if(!favor) cout << 0 << endl;
        else if(favor == total) cout << 1 << endl;
        else cout << favor << "/" << total << endl;
    }

    return 0;
}
