#include <iostream>
using namespace std;

const int mx = 5;
int a[mx];
int num = 23;
bool possible;

int setBit(int num, int pos){
    return (num | (1 << pos));
}

bool checkBit(int num, int pos){
    return (num & (1 << pos));
}

bool allZero(){
    for(int i = 0; i < mx; ++i){
        if(a[i]) return false;
    }
    return true;
}

void solve(int res, int mask){
    if(mask == (1 << mx) - 1){
        if(res == num) possible = true;
        return;
    }

    for(int i = 0; i < mx; ++i){
        if(!checkBit(mask, i)){
            solve(res + a[i], setBit(mask, i));
            solve(res - a[i], setBit(mask, i));
            solve(res * a[i], setBit(mask, i));
        }
    }
}

void scan(){
    for(int i = 0; i < mx; ++i){
        cin >> a[i];
    }
}

void print(){
    if(possible) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}

int main()
{
    while(true){
        scan();
        if(allZero()) break;

        possible = false;
        for(int i = 0; i < mx; ++i){
            solve(a[i], 1 << i);
        }

        print();
    }

    return 0;
}
