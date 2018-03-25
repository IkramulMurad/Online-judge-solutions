#include <bits/stdc++.h>

using namespace std;

long double cal(int a, int b, int c){
    int num = c - b, den = c - a;
    return (long double)num / den;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> v;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        v.push_back(x);
    }

    bool found = false;
    long double ans = 0;
    for(int i = 1; i < n; ++i){
        auto it = lower_bound(v.begin(), v.end(), v[i - 1] + m);
        if(it == v.end() or *it > v[i - 1] + m) --it;
        if(it <= v.begin() + i) continue;

        found = true;
        ans = max(ans, cal(v[i - 1], v[i], *it));
    }

    if(!found) cout << "-1" << endl;
    else cout << fixed << setprecision(9) << ans << endl;

    return 0;
}
