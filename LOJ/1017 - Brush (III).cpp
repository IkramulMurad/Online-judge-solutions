#include <bits/stdc++.h>

using namespace std;

int n, w, k, yy[110], dp[110][110];

int cal(int pos, int taken){
    if(pos >= n or taken > k) return 0;
    if(dp[pos][taken] != -1) return dp[pos][taken];

    int lo = yy[pos], hi = lo + w;
    int a = lower_bound(yy, yy + n, lo) - yy;
    int b = upper_bound(yy, yy + n, hi) - yy;
    int total = b - a;

    int ret1 = total + cal(b, taken + 1);
    int ret2 = cal(pos + 1, taken);

    return dp[pos][taken] = max(ret1, ret2);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        scanf("%d %d %d", &n, &w, &k);

        for(int i = 0; i < n; ++i){
            int x, y;
            scanf("%d %d", &x, &y);

            yy[i] = y;
        }

        sort(yy, yy + n);
        memset(dp, -1, sizeof dp);

        printf("Case %d: %d\n", t, cal(0, 1));
    }

    return 0;
}
