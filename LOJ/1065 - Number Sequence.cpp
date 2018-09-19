#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector <vector <LL> > matrix;
int mod;

matrix multiply(matrix a, matrix b){
    int n = a.size(), m = b[0].size(), p = a[0].size();
    matrix c(n, vector <LL> (m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            c[i][j] = 0;
            for(int k = 0; k < p; ++k){
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

matrix pow(matrix a, int p){
    if(p == 1) return a;
    if(p & 1) return multiply(a, pow(a, p - 1));
    matrix c = pow(a, p / 2);
    return multiply(c, c);
}

void setMod(int m){
    mod = 1;
    for(int i = 0; i < m; ++i) mod *= 10;
}

LL getAns(int a, int b, int n){
    if(n == 0) return a;
    if(n == 1) return b;

    matrix x(2, vector <LL> (2)), y(2, vector <LL> (1));
    x[0][0] = x[0][1] = x[1][0] = 1; x[1][1] = 0;
    y[0][0] = b; y[1][0] = a;

    matrix z = multiply(pow(x, n - 1), y);
    return z[0][0];
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int a, b, n, m;
        scanf("%d %d %d %d", &a, &b, &n, &m);

        setMod(m);
        LL ans = getAns(a, b, n);
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
