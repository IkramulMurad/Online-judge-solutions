#include <bits/stdc++.h>
using namespace std;

const int mx = 105;
int n, w, p[mx], c[mx], weight[mx];
bool impossible;
int ans, dp[mx][10005];

int cal(int i, int taken){
    if(i == n) return 0;
    if(dp[i][taken] != -1) return dp[i][taken];

    int p1 = 0, p2;
    if(taken + weight[i] <= w)
        p1 = p[i] + cal(i, taken + weight[i]);
    p2 = cal(i + 1, taken);

    return dp[i][taken] = max(p1, p2);
}

void solve(){
    impossible = false;
    if(w < 0){
        impossible = true;
        return;
    }

    memset(dp, -1, sizeof(dp));
    ans = cal(0, 0);
}

void print(int t){
    if(impossible) printf("Case %d: Impossible\n", t);
    else printf("Case %d: %d\n", t, ans);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        cin >> n >> w;
        for(int i = 0; i < n; ++i){
            cin >> p[i] >> c[i] >> weight[i];
            w -= c[i] * weight[i];
        }

        solve();
        print(t);
    }

    return 0;
}
