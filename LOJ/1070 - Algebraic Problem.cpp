#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef vector <LL> VL;
typedef vector <VL> VVL;

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

Matrix pow(Matrix a, int p){
    if(p == 1) return a;
    if(p & 1){
        Matrix b = pow(a, p - 1);
        return a * b;
    }
    
    Matrix c = pow(a, p / 2);
    return c * c;
}

void prepare(Matrix &a, int p, int q){
    VVL &x = a.a;
    x[0][0] = p; x[0][1] = -q; x[1][0] = 1; x[1][1] = 0;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int p, q, n;
        scanf("%d %d %d", &p, &q, &n);

        Matrix a(2, 2);
        prepare(a, p, q);

        LL ans;

        if(n > 1){
            a = pow(a, n - 1);
            ans = a.a[0][0] * p + a.a[0][1] * 2;
        }
        else{
            if(n == 0) ans = 2;
            else ans = p;
        }

        printf("Case %d: %llu\n", t, ans);
    }

    return 0;
}
