#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 55;
int n, lastItem[mx];

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void init(){
    for(int i = 0; i < n; ++i){
        lastItem[i] = 0;
    }
}

int sqrt(int x){
    if(x <= 1) return x;

    int rng = x / 2;
    int ans = 0;
    for(int i = 0; i <= rng; ++i){
        if(i * i <= x){
            ans = i;
        }
        else break;
    }

    return ans;
}

bool square(int x){
    return (sqrt(x) * sqrt(x) == x);
}

bool put(int num, int peg){
    if(peg == n) return false;
    if(square(lastItem[peg] + num)){
        lastItem[peg] = num;
        return true;
    }
    if(lastItem[peg] == 0){
        lastItem[peg] = num;
        return true;
    }
    put(num, peg + 1);
}

void solve(){
    cin >> n;
    init();

    int i = 0;
    while(put(i + 1, 0)){
        ++i;
    }

    cout << i << endl;
}

int main()
{
    //fileInput();

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        solve();
    }

    return 0;
}
