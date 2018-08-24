#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int n;
        cin >> n;

        map <char, int> m;
        for(int i = 0; i < n; ++i){
            int x;
            char c;
            cin >> c >> x;
            m[c] = x;
        }

        int l, ans = 0;
        cin >> l;
        getchar();
        for(int i = 0; i < l; ++i){
            string line;
            getline(cin, line);
            for(int j = 0; j < line.size(); ++j){
                ans += m[line[j]];
            }
            //cout << ans << endl;
        }

        printf("%d.%02d$\n", ans / 100, ans % 100);
    }

    return 0;
}
