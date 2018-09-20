#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector <LL> VL;
typedef vector <VL> VVL;
int mod;

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

void prepare(Matrix &p, Matrix &q, int a[]){
    VVL &x = p.a, &y = q.a;
    x[0][0] = a[0]; x[0][1] = a[1]; x[0][2] = 0;    x[0][3] = 0;    x[0][4] = 0;    x[0][5] = a[2];
    x[1][0] = 1;    x[1][1] = 0;    x[1][2] = 0;    x[1][3] = 0;    x[1][4] = 0;    x[1][5] = 0;
    x[2][0] = 0;    x[2][1] = 1;    x[2][2] = 0;    x[2][3] = 0;    x[2][4] = 0;    x[2][5] = 0;
    x[3][0] = 0;    x[3][1] = 0;    x[3][2] = a[5]; x[3][3] = a[3]; x[3][4] = a[4]; x[3][5] = 0;
    x[4][0] = 0;    x[4][1] = 0;    x[4][2] = 0;    x[4][3] = 1;    x[4][4] = 0;    x[4][5] = 0;
    x[5][0] = 0;    x[5][1] = 0;    x[5][2] = 0;    x[5][3] = 0;    x[5][4] = 1;    x[5][5] = 0;
    
    y[0][0] = a[8]; y[1][0] = a[7]; y[2][0] = a[6]; y[3][0] = a[11]; y[4][0] = a[10]; y[5][0] = a[9];
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int a[12];
        for(int i = 0; i < 12; ++i) scanf("%d", &a[i]);
        
        Matrix p(6, 6), q(6, 1);
        prepare(p, q, a);

        int m;
        scanf("%d %d", &mod, &m);

        printf("Case %d:\n", t);
        for(int i = 0; i < m; ++i){
            int n;
            scanf("%d", &n);

            int ansf = 0, ansg = 0;
            if(n <= 2){
                ansf = a[6 + n] % mod;
                ansg = a[9 + n] % mod;
            }
            else{
                Matrix r = pow(p, n - 2);
                Matrix s = r * q;
                ansf = s.a[0][0];
                ansg = s.a[3][0];
            }
            printf("%d %d\n", ansf, ansg);
        }
    }

    return 0;
}
