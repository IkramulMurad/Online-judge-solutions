#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mx = 205;
int n, q, d, m;
int a[mx], b[mx];
LL dp[mx][10][20];

void scan(){
    cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> a[i];
}

int mod(int n, int d){
    if(n < 0) return (n % d) + d;
    return n % d;
}

LL cal(int i, int taken, int total){
    if(taken == m) return (total == 0);
    if(i == n) return 0;
    if(dp[i][taken][total] != -1) return dp[i][taken][total];

    LL a1 = cal(i + 1, taken + 1, (total + b[i]) % d);
    LL a2 = cal(i + 1, taken, total);

    return dp[i][taken][total] = a1 + a2;
}

LL solve(int d, int m){
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; ++i){
        b[i] = mod(a[i], d);
    }

    return cal(0, 0, 0);
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        scan();
        printf("Case %d:\n", t);
        for(int i = 0; i < q; ++i){
            cin >> d >> m;
            cout << solve(d, m) << endl;
        }
    }

    return 0;
}
