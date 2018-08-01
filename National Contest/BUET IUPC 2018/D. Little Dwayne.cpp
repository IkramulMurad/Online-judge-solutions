#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int d, k;
        cin >> d >> k;

        int ans = 0;
        for(int i = 0; i < d; ++i){
            int x; 
            cin >> x;

            if(x > k) ans += x - k;
        }
        printf("%d\n", ans);
    }

    return 0;
}
