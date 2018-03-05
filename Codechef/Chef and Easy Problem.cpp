#include <bits/stdc++.h>
using namespace std;

void scan(int n, int a[], int b[][31]){
    for(int i = 0; i < 31; ++i) b[0][i] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        for(int j = 0; j < 31; ++j){
            bool x = a[i] & (1 << j);
            b[i][j] = b[i-1][j] + x;
            //cerr << b[i][j] << " ";
        }
        //cerr << endl;
    }
}

int on(int n, int pos){
    return (n | (1 << pos));
}

int cal(int d[], int x){
    int ans = 0;
    for(int i = 0; i < 31; ++i){
        if(2*d[i] < x){
            ans = on(ans, i);
        }
    }
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, q;
    cin >> n >> q;

    int a[n+1], b[n+1][31];
    scan(n, a, b);

    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;

        int d[31];
        for(int j = 0; j < 31; ++j){
            d[j] = b[r][j] - b[l-1][j];
        }

        int x = r - (l-1);
        int ans = cal(d, x);

        //for(int j = 0; j < 31; ++j) cerr << bool(ans & (1 << i)) << " ";
        cout << ans << endl;
    }

    return 0;
}
