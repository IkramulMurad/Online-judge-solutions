#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int mx = 32;
const int mmx = 2;
int mod;
 
 
struct Matrix{
    int n, m;
    LL a[mx][mx];
 
    Matrix() : n(mx), m(mx) {}
    Matrix(int n, int m) : n(n), m(m) {}
 
    void resize(int n, int m){
        this->n = n;
        this->m = m;
    }
 
    void print(){
        cerr << "n: " << n << ", m: " << m << endl;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cerr << a[i][j] << " ";
            }
            cerr << "," << endl;
        }
        cerr << endl;
    }
 
    void makeI(){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(i == j) a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
    }
 
    void make0(){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                a[i][j] = 0;
            }
        }
    }
 
    Matrix add(Matrix &b){
        Matrix c(b.n, b.m);
 
        for(int i = 0; i < c.n; ++i){
            for(int j = 0; j < c.m; ++j){
                c.a[i][j] = this->a[i][j] + b.a[i][j];
                c.a[i][j] %= mod;
            }
        }
        return c;
    }
 
    Matrix multiply(Matrix &b){
        Matrix c(this->n, b.m);
 
        for(int i = 0; i < c.n; ++i){
            for(int j = 0; j < c.m; ++j){
                c.a[i][j] = 0;
                for(int k = 0; k < this->m; ++k){
                    c.a[i][j] += this->a[i][k] * b.a[k][j];
                    c.a[i][j] %= mod;
                }
            }
        }
        return c;
    }
 
    Matrix pow(LL p){
        Matrix c(this->n, this->m);
        c.makeI();
 
        while(p){
            if(p & 1){
                c = c.multiply(*this);
                --p;
            }
            else{
                *this = this->multiply(*this);
                p /= 2;
            }
        }
        return c;
    }
};
 
struct MatMat{
    int n, m;
    Matrix mm[mmx][mmx];
 
    MatMat() : n(mmx), m(mmx) {}
    MatMat(int n, int m) : n(n), m(m) {}
 
    void resize(int n, int m, int p, int q){
        this->n = n;
        this->m = m;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                mm[i][j].resize(p, q);
            }
        }
    }

    void makeI(){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(i == j) mm[i][j].makeI();
                else mm[i][j].make0();
            }
        }
    }
 
    void make0(){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                mm[i][j].make0();
            }
        }
    }
 
    void print(){
        cerr << "nn: " << n << ", mm: " << m << endl;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                mm[i][j].print();
                cerr << endl;
            }
            cerr << "," << endl;
        }
        cerr << endl;
    }
 
    MatMat multiply(MatMat &b){
        MatMat c;
        c.resize(this->n, this->m, this->mm[0][0].n, this->mm[0][0].m);
 
        for(int i = 0; i < c.n; ++i){
            for(int j = 0; j < c.m; ++j){
                c.mm[i][j].make0();
                for(int k = 0; k < this->m; ++k){
                    Matrix x = this->mm[i][k].multiply(b.mm[k][j]);
                    c.mm[i][j] = c.mm[i][j].add(x);
                }
            }
        }
        return c;
    }
 
    MatMat pow(LL p){
        MatMat c;
        c.resize(this->n, this->m, this->mm[0][0].n, this->mm[0][0].m);
        c.makeI();
 
        while(p){
            if(p & 1){
                c = this->multiply(c);
                --p;
            }
            else{
                *this = this->multiply(*this);
                p /= 2;
            }
        }
        return c;
    }
};
 
 
int main(){
    //freopen("in.txt", "r", stdin);
 
    int tc;
    scanf("%d", &tc);
 
    for(int t = 1; t <= tc; ++t){
        mod = 10;
        int n, k;
        scanf("%d %d", &n, &k);
 
        Matrix x(n, n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                scanf("%lld", &x.a[i][j]);
            }
        }
 
        MatMat a(2, 2), b(2, 1);
        a.mm[0][0].resize(n, n); a.mm[0][1].resize(n, n);
        a.mm[1][0].resize(n, n); a.mm[1][1].resize(n, n);
        b.mm[0][0].resize(n, n); b.mm[1][0].resize(n, n);
 
        a.mm[0][0].makeI(); a.mm[1][0].make0();
        a.mm[0][1] = a.mm[1][1] = b.mm[0][0] = b.mm[1][0] = x;
 
        a = a.pow(k - 1);
        a = a.multiply(b);
 
        printf("Case %d:\n", t);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                printf("%lld", a.mm[0][0].a[i][j]);
            }
            puts("");
        }
    }
 
    return 0;
}
