#include <bits/stdc++.h>
using namespace std;

void scan(int n, int p[], int q[], int d[]){
    for(int i = 0; i < n; ++i){
        cin >> p[i] >> q[i] >> d[i];
    }
}

double calculate(int n, int p[], int q[], int d[]){
    double ans = 0;
    for(int i = 0; i < n; ++i){
        double x = double(d[i])/100.0;
        ans += x * x * p[i] * q[i];
    }
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int n;
        cin >> n;

        int p[n], q[n], d[n];
        scan(n, p, q, d);

        double ans = calculate(n, p, q, d);
        cout << fixed << setprecision(6) << ans << endl;
    }

    return 0;
}
