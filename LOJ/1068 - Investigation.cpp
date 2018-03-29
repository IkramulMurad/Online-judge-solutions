#include <bits/stdc++.h>
using namespace std;

const int mx = 100;
vector <int> num;
int dp[10][2][mx][mx];
int a, b, k;

int cal(int pos, bool small, int n, int dgtSum){
    if(pos == num.size()) return (n == 0 and dgtSum == 0);
    int &ret = dp[pos][small][n][dgtSum];
    if(ret != -1) return ret;

    ret = 0;
    int lim = small ? 9 : num[pos];

    for(int i = 0; i <= lim; ++i){
        ret += cal(pos + 1, small | (i < num[pos]), (n * 10 + i) % k, (dgtSum + i) % k);
    }
    //ret += cal(pos + 1, 1, n, dgtSum);

    return ret;
}

int solve(int x){
    if(x == 0 or k > 81) return 0;
    if(k == 1) return x;

    num.clear();
    while(x){
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());

    memset(dp, -1, sizeof(dp));
    int ans = cal(0, 0, 0, 0) - 1;
    return ans;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        cin >> a >> b >> k;

        int ans = solve(b) - solve(a - 1);
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
