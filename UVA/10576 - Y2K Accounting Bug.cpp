#include <iostream>
#include <cstdio>
using namespace std;

int s, d;
int ans;

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int setBit(int num, int pos){
    return (num | (1 << pos));
}

bool checkBit(int num, int pos){
    return (num & (1 << pos));
}

int getAns(int mask){
    int ans = 0;
    for(int i = 0; i < 12; ++i){
        if(checkBit(mask, i)){
            ans += s;
        }
        else ans -= d;
    }
    return ans;
}

bool satisfy(int mask){
    for(int i = 0; i < 8; ++i){
        int ans = 0;
        for(int j = 0; j < 5; ++j){
            if(checkBit(mask, i + j)) ans += s;
            else ans -= d;
        }
        if(ans >= 0) return false;
    }
    return true;
}

void solve(int i, int mask){
    if(i == 12){
        if(satisfy(mask)){
            ans = max(ans, getAns(mask));
        }
        return;
    }

    solve(i + 1, setBit(mask, i));
    solve(i + 1, mask);
}

void print(){
    if(ans) cout << ans << endl;
    else cout << "Deficit" << endl;
}

int main()
{
    //fileInput();

    while(cin >> s >> d){
        ans = 0;
        solve(0, 0);
        print();
    }

    return 0;
}
