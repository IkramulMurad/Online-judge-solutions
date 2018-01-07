#include <iostream>
using namespace std;

const int mx = 35;
int a[mx][mx], d[mx];
int n, m, val;

void scan(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
            if(!j) d[i] = a[i][j];
        }
    }
    cin >> val;
}

int binSearch(int val, int a[], int rng){
    int ret = -1;
    int lo = 0, hi = rng - 1;

    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(a[mid] == val){
            ret = mid;
            break;
        }
        else if(a[mid] < val){
            ret = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    return ret;
}

void solve(){
    int idx, jdx;
    idx = binSearch(val, d, n);

    if(idx == -1) cout << 0 << endl;
    else{
        jdx = binSearch(val, a[idx], m);
        if(a[idx][jdx] == val) cout << 1 << endl;
        else cout << 0 << endl;
    }
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
