#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
int a[mx];
int n, h;
int mxPile;

void scan(){
    mxPile = 0;
    cin >> n >> h;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mxPile = max(mxPile, a[i]);
    }
}

int check(int k){
    int hour = 0;
    for(int i = 0; i < n; ++i){
        hour += a[i]/k;
        if(a[i] % k) ++hour;
    }
    return hour;
}

int binSearch(int s, int t){
    int ret = t;
    while(s <= t){
        int mid = (s + t)/2;
        int hour = check(mid);

        if(hour <= h){
            ret = mid;
            t = mid - 1;
        }
        else if(hour > h){
            s = mid + 1;
        }
    }
    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        scan();
        int ans = binSearch(1, mxPile);
        cout << ans << endl;
    }

    return 0;
}
