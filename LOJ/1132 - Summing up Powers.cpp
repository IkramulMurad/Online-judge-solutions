#include <bits/stdc++.h>
using namespace std;
typedef unsigned int UI;
typedef unsigned long long LL;
typedef vector <UI> VL;
typedef vector <VL> VVL;
const int mx = 52;
UI ncr[mx][mx];

struct Matrix{
    int n, m;
    VVL a;
    Matrix(){}
    Matrix(int n, int m){
        this->n = n;
        this->m = n;
        this->a.resize(n, VL(m));
    }
    
    friend Matrix operator*(Matrix &a, Matrix &b){
        Matrix c(a.n, b.m);
        VVL &x = a.a, &y = b.a, &z = c.a;
        for(int i = 0; i < c.n; ++i){
            for(int j = 0; j < c.m; ++j){
                z[i][j] = 0;
                for(int k = 0; k < b.n; ++k){
                    z[i][j] += x[i][k] * y[k][j];
                }
            }
        }
        return c;
    }
};

Matrix pow(Matrix a, LL p){
    if(p == 1) return a;
    if(p & 1){
        Matrix b = pow(a, p - 1);
        return a * b;
    }
    
    Matrix c = pow(a, p / 2);
    return c * c;
}

void pre(){
    ncr[0][0] = ncr[1][1] = 1;
    for(int i = 1; i < mx; ++i){
        ncr[i][0] = 1;
        for(int j = 1; j < mx; ++j){
            ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
        }
    }
}

int main(){
    //freopen("in.txt", "r", stdin);

    pre();
    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        LL n, k;
        scanf("%lld %lld", &n, &k);

        Matrix a(k + 2, k + 2), b(k + 2, 1);
        
        //prepare
        for(int i = 0; i < k + 2; ++i){
            b.a[i][0] = 1;
        }

        for(int i = 0; i < k + 2; ++i){
            if(i == 0) a.a[0][i] = 1;
            else a.a[0][i] = ncr[k][i - 1];
        }

        for(int i = 1; i < k + 2; ++i){
            for(int j = 0; j < k + 2; ++j){
                if(i > j) a.a[i][j] = 0;
                else a.a[i][j] = ncr[k + 1 - i][j - i];
            }
        }

        //calculation
        LL ans;
        if(n == 1) ans = 1;
        else{
            Matrix c = pow(a, n - 1);
            c = c * b;
            ans = c.a[0][0];
        }
        
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
