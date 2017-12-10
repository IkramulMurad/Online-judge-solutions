#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 20 + 3;
int n, ans, seq, tracks;
int a[mx];

void scan(){
    ans = seq = 0;

    cin >> tracks;
    for(int i = 0; i < tracks; ++i){
        cin >> a[i];
    }
}

int checkBit(int num, int pos){
    return (num & (1 << pos));
}

int setBit(int num, int pos){
    return (num | (1 << pos));
}

void print(){
    for(int i = 0; i < tracks; ++i){
        if(checkBit(seq, i)){
            cout << a[i] << " ";
        }
    }
    cout << "sum:" << ans <<endl;
}

void solve(int cur, int total, int mask){
    if(cur == tracks){
        if(ans < total){
            ans = total;
            seq = mask;
        }
        return;
    }

    if(total + a[cur] <= n) solve(cur + 1, total + a[cur], setBit(mask, cur));
    solve(cur + 1, total, mask);
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    while(cin >> n){
        scan();
        solve(0, 0, 0);
        print();
    }

    return 0;
}
