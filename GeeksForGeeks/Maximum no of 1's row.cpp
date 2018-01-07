#include <iostream>

using namespace std;

const int mx = 45;
bool a[mx][mx];
int n, m;

void scan(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
}

void solve(){
    int ans = 0, kount = 0;
    for(int i = 0; i < n; ++i){
        int k = 0;
        for(int j = 0; j < m; ++j){
            if(a[i][j]) ++k;
        }
        if(k > kount){
            kount = k;
            ans = i;
        }
    }

    cout << ans << endl;
}

int main()
{
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        scan();
        solve();
    }

    return 0;
}
