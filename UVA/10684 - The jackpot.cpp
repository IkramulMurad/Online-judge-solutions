#include <bits/stdc++.h>
using namespace std;

int cal(int n, int a[]){
    int ans = 0, maxHere = 0;
    for(int i = 0; i < n; ++i){
        maxHere += a[i];
        ans = max(ans, maxHere);
        maxHere = max(maxHere, 0);
    }
    return ans;
}

int main()
{
    int n;
    while(cin >> n and n){
        int a[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        int ans = cal(n, a);
        if(ans) cout << "The maximum winning streak is " << ans << "." << endl;
        else cout << "Losing streak." << endl;
    }
    return 0;
}
