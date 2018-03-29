#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mx = 1e6;

int main()
{
    //freopen("in", "r", stdin);

    LL x, a[mx], idx = 0;
    map<LL, LL> mp;
    map<LL, bool> printed;

    while(cin >> x){
        a[idx++] = x;
        mp[x]++;
    }

    for(int i = 0; i < idx; ++i){
        LL n = a[i];
        if(!printed[n]){
            cout << n << " " << mp[n] << endl;
            printed[n] = true;
        }
    }

    return 0;
}
