#include <bits/stdc++.h>

using namespace std;

int cal(int n, int k){
    if(k == 1) return n;
    if(n == 1) return 1;
    if(n == k) return cal(n-1, k);

    int ans;
    if(n < k){
        ans = (k % n) + cal(n-1, k);
        if(ans > n) ans -= n;
    }
    else{
        int ret = cal(n - n / k, k);
        if(ret <= n % k){
            ans = (n / k) * k + ret;
        }
        else{
            int x = ret - n % k;
            ans = (k * x) / (k - 1);
        }
    }

    return ans;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n,k;
        scanf("%d %d", &n, &k);

        printf("Case %d: %d\n", t, cal(n,k));
    }

    return 0;
}
