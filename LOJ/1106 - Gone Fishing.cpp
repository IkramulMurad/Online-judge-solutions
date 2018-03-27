#include <bits/stdc++.h>
using namespace std;

const int mx = 30;
int n, h, ans;
int f[mx], d[mx], t[mx], spent[mx];
int dp[mx][200][200];

struct Next{
    int a, b, c;
    Next(int x, int y, int z) : a(x), b(y), c(z) {}
    Next() {}
} path[mx][200][200];

void scan(){
    cin >> n >> h;
    for(int i = 0; i < n; ++i) cin >> f[i];
    for(int i = 0; i < n; ++i) cin >> d[i];
    for(int i = 0; i < n - 1; ++i) cin >> t[i];
}

void print(int t){
    printf("Case %d:\n", t);
    for(int i = 0; i < n; ++i){
        if(i) printf(", ");
        printf("%d", spent[i]);
    }
    printf("\n");
    printf("Number of fish expected: %d\n", ans);
}

int cal(int lake, int interval, int remTime){
    if(lake == n) return 0;
    if(remTime <= 0) return 0;

    Next &pet = path[lake][interval][remTime];
    int &ret = dp[lake][interval][remTime];
    if(ret != -1) return ret;

    int a1 = max(f[lake] - d[lake] * interval, 0) + cal(lake, interval + 1, remTime - 1);
    int a2 = cal(lake + 1, 0, remTime - t[lake]);

    if(a1 >= a2) pet = Next(lake, interval + 1, remTime - 1);
    else pet = Next(lake + 1, 0, remTime - t[lake]);

    return ret = max(a1, a2);
}

void findPath(int a, int b, int c){
    if(a >= n or c <= 0) return;

    int x = path[a][b][c].a;
    int y = path[a][b][c].b;
    int z = path[a][b][c].c;

    if(a == x) spent[x] += 5;
    findPath(x, y, z);
}

void solve(){
    memset(dp, -1, sizeof(dp));
    ans = cal(0, 0, h * 12);

    memset(spent, 0, sizeof(spent));
    findPath(0, 0, h * 12);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        scan();
        solve();
        print(t);
    }

    return 0;
}
