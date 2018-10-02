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

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n;
        scanf("%d", &n);
        
        Matrix a(4, 4), b(4, 1);
        a.a[0][0] = a.a[0][1] = a.a[0][2] = a.a[0][3] = 1;          //1 1 1 1
        a.a[1][0] = 1; a.a[1][1] = a.a[1][2] = a.a[1][3] = 0;       //1 0 0 0
        a.a[2][0] = 0; a.a[2][1] = 1; a.a[2][2] = 0; a.a[2][3] = 1; //0 1 0 1
        a.a[3][0] = 0; a.a[3][1] = 1; a.a[3][2] = 1; a.a[3][3] = 0; //0 1 0 1

        b.a[0][0] = 2; b.a[1][0] = b.a[2][0] = b.a[3][0] = 1;       //2 1 1 1


        int ans;
        if(n <= 2){
            ans = n;
        }
        else{
            Matrix c = pow(a, n - 2);
            c = c * b;
            ans = c.a[0][0];
        }

        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
