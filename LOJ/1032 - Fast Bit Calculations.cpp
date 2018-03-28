#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mx = 35;
LL dp[mx][2][2][2][mx];
vector <bool> num;

LL cal(int pos, bool start, bool small, bool prev, int kount){
    if(pos == num.size()) return kount;

    LL &ret = dp[pos][start][small][prev][kount];
    if(ret != -1) return ret;

    int lim = small ? 1 : num[pos];
    ret = 0;
    if(!start){
        ret += cal(pos + 1, 0, small | num[pos], 0, kount);
        if(lim) ret += cal(pos + 1, 0, small, 1, prev + kount);
    }
    else{
        ret += cal(pos + 1, 0, small, 1, 0);
        ret += cal(pos + 1, 1, 1, 1, 0);
    }

    return ret;
}

LL solve(int n){
    if(n <= 2) return 0;

    num.clear();
    while(n){
        num.push_back(n % 2);
        n /= 2;
    }
    reverse(num.begin(), num.end());

    memset(dp, -1, sizeof(dp));
    LL ans = cal(0, 1, 0, 0, 0);
    return ans;
}

int main()
{
    //freopen("in", "r", stdin);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int n;
        cin >> n;

        LL ans = solve(n);
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
