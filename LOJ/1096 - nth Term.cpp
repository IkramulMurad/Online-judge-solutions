#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector <LL> VL;
typedef vector <VL> VVL;
const int mod = 10007;

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
                    z[i][j] %= mod;
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

void prepare(Matrix &p, Matrix &q, int a, int b, int c){
    VVL &x = p.a, &y = q.a;
    x[0][0] = a;
    x[0][1] = 0;
    x[0][2] = b;
    x[0][3] = 1;
    x[1][0] = 1;
    x[1][1] = 0;
    x[1][2] = 0;
    x[1][3] = 0;
    x[2][0] = 0;
    x[2][1] = 1;
    x[2][2] = 0;
    x[2][3] = 0;
    x[3][0] = 0;
    x[3][1] = 0;
    x[3][2] = 0;
    x[3][3] = 1;
    
    y[0][0] = 0;
    y[1][0] = 0;
    y[2][0] = 0;
    y[3][0] = c;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n, a, b, c;
        scanf("%d %d %d %d", &n, &a, &b, &c);
        
        Matrix p(4, 4), q(4, 1);
        prepare(p, q, a, b, c);

        int ans = 0;
        if(n > 2){
            p = pow(p, n - 2);
            Matrix r = p * q;
            ans = r.a[0][0];
        }

        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
