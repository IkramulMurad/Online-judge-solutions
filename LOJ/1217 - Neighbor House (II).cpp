#include <bits/stdc++.h>
using namespace std;

const int mx = 1005;
int a[mx], dp[mx][2];
int n;

int cal(int i, bool firstTaken){
    if(i > n) return 0;
    if(i == n and firstTaken) return 0;
    if(dp[i][firstTaken] != -1) return dp[i][firstTaken];

    int a1, a2;
    if(i == 1) a1 = a[i] + cal(i + 2, true);
    else a1 = a[i] + cal(i + 2, firstTaken);
    a2 = cal(i + 1, firstTaken);

    return dp[i][firstTaken] = max(a1, a2);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        memset(dp, -1, sizeof(dp));
        int ans = cal(1, 0);

        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
