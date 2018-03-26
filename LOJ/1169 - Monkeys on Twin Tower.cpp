#include <bits/stdc++.h>
using namespace std;

const int mx = 1005;
int n, ans;
int a[mx], b[mx], j[mx], k[mx];
int dp[mx][2];

void scan(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    for(int i = 0; i < n - 1; ++i) cin >> j[i];
    for(int i = 0; i < n - 1; ++i) cin >> k[i];
}

void print(int t){
    printf("Case %d: %d\n", t, ans);
}

int cal(int i, int tower){
    if(i == n - 1){
        if(!tower) return a[i];
        else return b[i];
    }
    if(dp[i][tower] != -1) return dp[i][tower];

    int a1, a2;
    if(!tower){
        a1 = a[i] + cal(i + 1, tower);
        a2 = a[i] + j[i] + cal(i + 1, tower ^ 1);
    }
    else{
        a1 = b[i] + cal(i + 1, tower);
        a2 = b[i] + k[i] + cal(i + 1, tower ^ 1);
    }

    return dp[i][tower] = min(a1, a2);
}

void solve(){
    memset(dp, -1, sizeof(dp));
    int x = cal(0, 0);

    memset(dp, -1, sizeof(dp));
    int y = cal(0, 1);

    ans = min(x, y);
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        scan();
        solve();
        print(t);
    }

    return 0;
}
