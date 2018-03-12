#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
 
const int mx = 1e5 + 5;
int n;
int a[mx], b[mx];
LL sum[mx];
 
void scan(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
}
 
void cumSum(){
    sum[0] = a[0];
    for(int i = 1; i < n; ++i) sum[i] = sum[i-1] + a[i];
}
 
void init(){
    for(int i = 0; i < n; ++i) b[i] = 0;
}
 
int main()
{
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
 
    for(int t = 1; t <= tc; ++t){
        scan();
        cumSum();
        init();
 
        for(int k = 0; k < n; ++k){
            if(k){
                int i = lower_bound(sum, sum + n, sum[k-1] - a[k]) - sum;
                int j = k;
 
                b[i] += 1;
                b[j] -= 1;
            }
 
            if(k < n-1){
                int i = k + 1;
                int j = lower_bound(sum, sum + n, sum[k] + a[k] + 1) - sum + 1;
 
                b[i] += 1;
                b[j] -= 1;
            }
        }
 
        for(int i = 0; i < n; ++i){
            if(i){
                cout << " ";
                b[i] += b[i-1];
            }
            cout << b[i];
        }
        cout << endl;
    }
 
    return 0;
} 
