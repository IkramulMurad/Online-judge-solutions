#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
 
typedef long long LL;
 
int m, n;
int a[10];
LL dp[12][12];
 
LL cal(int idx, int lastDigit){
    if(idx == n) return 1;
 
    LL &ret = dp[idx][lastDigit];
    if(ret != -1) return ret;
 
    ret = 0;
    for(int i = 0; i < m; ++i){
        if(abs(lastDigit - a[i]) <= 2 or !lastDigit){
            ret += cal(idx + 1, a[i]);
        }
    }
    return ret;
}
 
int main(){
    //freopen("in.txt", "r", stdin);
 
    int tc;
    cin >> tc;
 
    for(int t = 1; t <= tc; ++t){
        cin >> m >> n;
        for(int i = 0; i < m; ++i){
            cin >> a[i];
        }
 
        memset(dp, -1, sizeof(dp));
        cout << "Case " << t << ": " << cal(0, 0) << endl;
    }
 
    return 0;
}
