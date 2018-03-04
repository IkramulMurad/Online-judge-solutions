#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int n;
        cin >> n;

        map<int, int> m;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            m[x]++;
        }

        int ans = 0;
        for(auto it = m.begin(); it != m.end(); ++it){
            ans += it->second - 1;
        }
        cout << ans << endl;
    }

    return 0;
}
