#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 1e9;
const int mx = 25;
int a[mx][mx], dp[mx][mx];
int n, m, sx, sy, ans;

void scan(){
    cin >> n >> m >> sx >> sy;
    --sx; --sy;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
}

int cal(int i, int j){
    if(i == sx and j == sy) return 0;
    if(i < 0 or j < 0) return inf;
    if(dp[i][j] != -1) return dp[i][j];

    int ret = inf;
    ret = min(ret, a[i][j] + cal(i - 1, j));
    ret = min(ret, a[i][j] + cal(i, j - 1));

    return dp[i][j] = ret;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    ans = a[sx][sy] - cal(n - 1, m - 1);
}

void print(){
    if(ans < 0) cout << "N" << endl;
    else cout << "Y " << ans << endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scan();
    solve();
    print();

    return 0;
}
