// #define DEBUGM 1
// #define DEBUGG 2
// #define DEBUGC 3
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL inf = 1e18;
LL dp[19][2][524288];
vector <int> v, s;

bool check(int n, int pos){
    return (n & (1 << pos));
}

int set(int n, int pos){
    return (n | (1 << pos));
}

void print(vector <int> v){
    for(int i = 0; i < v.size(); ++i){
        cerr << v[i] << " ";
    }
    cerr << endl;
}

void printMask(int x){
    if(x == 0){
        cerr << x;
    }

    vector <int> v;
    while(x){
        v.push_back(x % 2);
        x /= 2;
    }
    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); ++i){
        cerr << v[i];
    }
}

LL expo(int base, int pow){
    if(pow == 0) return 1;
    if(pow & 1) return base * expo(base, pow - 1);
    return expo(base, pow / 2) * expo(base , pow / 2);
}

LL cal(int pos, bool small, int mask){
    if(pos == s.size()){
        #ifdef DEBUGC
        cerr << "base: " << 0 << endl;
        #endif
        return 0;
    }

    LL &ret = dp[pos][small][mask];
    if(ret != -1){
        #ifdef DEBUGC
        cerr << "mem: " << ret << endl;
        #endif
        return ret;
    }

    ret = -inf;
    bool valueSet = false;
    int lim = small ? 9 : v[pos];
    for(int i = 0; i < s.size(); ++i){
        // bool chk = !check(mask, i);
        // int sm = s[i]; int tg = v[pos];
        // bool ff = !found;
        if(!check(mask, i) and (small | s[i] <= v[pos])){
            valueSet = true;
            #ifdef DEBUGC
            cerr << "pos: " << pos << ", small: " << small << ", mask: "; printMask(mask); cerr << ", digit: " << s[i] << endl;
            #endif
            LL res = s[i] * expo(10, s.size() - pos - 1);
            LL cl = cal(pos + 1, small | (s[i] < v[pos]), set(mask, i));
            ret = max(ret, res + cl);
        }
    }

    return ret;
}

LL getResult(LL a, LL b){
    v.clear();
    while(b){
        v.push_back(b % 10);
        b /= 10;
    }
    reverse(v.begin(), v.end());

    s.clear();
    while(a){
        s.push_back(a % 10);
        a /= 10;
    }
    sort(s.begin(), s.end());

    #ifdef DEBUGG
    print(v);
    print(s);
    #endif

    memset(dp, -1, sizeof(dp));
    return cal(0, s.size() < v.size(), 0);
}

int main(){
    #ifdef DEBUGM
    freopen("in.txt", "r", stdin);
    #endif

    LL a, b;
    cin >> a >> b;

    cout << getResult(a, b) << endl;

    return 0;
}
