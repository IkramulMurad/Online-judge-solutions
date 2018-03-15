#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
typedef long long LL;
const int mod = 1000007;
const int mx = 1e5 + 5;
int k, c, n;
LL dif[mx], a[mx], sum;
 
void scan(){
    scanf("%d %d %d %d", &k, &c, &n, &a[0]);
    for(int i = 1; i < n; ++i){
        a[i] = (k * a[i - 1] + c) % mod;
    }
}
 
void cal(){
    dif[n - 1] = sum = 0;
    for(int i = n - 2, j = 1; i >= 0; --i, ++j){
        dif[i] = LL(a[i + 1] - a[i]) * j + dif[i + 1];
        sum += dif[i];
    }
}
 
void print(int t){
    printf("Case %d: %lld\n", t, sum);
}
 
int main()
{
    int tc;
    scanf("%d", &tc);
 
    for(int t = 1; t <= tc; ++t){
        scan();
        sort(a, a + n);
        cal();
        print(t);
    }
 
    return 0;
}
