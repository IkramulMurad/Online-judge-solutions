#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

const int mx = 16;
double d[mx][mx], round[mx][mx];
char country[mx][mx];

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            if(!i) round[i][j] = 1;
            else round[i][j] = 0;
        }
    }
}

void scan(){
    for(int i = 0; i < mx; ++i){
        cin >> country[i];
    }

    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            cin >> d[i][j];
            d[i][j] /= 100;
        }
    }
}

void calculate(){
    for(int k = 0; k < 4; ++k){
        for(int i = 0; i < mx; ++i){
            int y = 1 << k;
            int x = i / y;

            if(x & 1) x = (x - 1) * y;
            else x = (x + 1) * y;

            for(int j = 0; j < y; ++j){
                int op = x + j;
                round[k + 1][i] += d[i][op] * round[k][op];
            }
            round[k + 1][i] *= round[k][i];
        }
    }
}

void print(){
    for(int i = 0; i < mx; ++i){
        cout << setw(10) << left << country[i] << " p=";
        cout << fixed << setprecision(2) << round[4][i] * 100 << "%" << endl;
    }
}

int main()
{
    //file();

    reset();
    scan();
    calculate();
    print();

    return 0;
}
