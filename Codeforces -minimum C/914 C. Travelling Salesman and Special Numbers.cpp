#define DBG_FILE 1
#define DBG_FUN 2
#define DBG_DP 3

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;
const int mx = 1005;
LL dp[mx][mx][2];
int stepRqd[mx];
vector <int> v;
int k;

int bitCount(int x){
    int ans = 0;
    while(x){
        ans += bool(x & 1);
        x >>= 1;
    }
    return ans;
}

void preCal(){
    stepRqd[0] = stepRqd[1] = 0;
    for(int i = 2; i < mx; ++i){
        stepRqd[i] = 1 + stepRqd[bitCount(i)];
    }
}

LL cal(int pos, int totalSet, bool small){
    // if(stepRqd[totalSet] > k){
    //     return 0;
    // }
    if(pos == v.size()){
        return bool(1 + stepRqd[totalSet] == k);
    }

    LL &ret = dp[pos][totalSet][small];
    if(ret != -1){
        return ret;
    }

    ret = 0;
    int lim = small ? 1 : v[pos];
    for(int i = 0; i <= lim; ++i){
        ret = (ret + cal(pos + 1, totalSet + bool(i), small | (i < v[pos]))) % mod;
    }

    return ret;
}

LL getAns(string s, int k){
    v.clear();
    for(int i = 0; i < s.size(); ++i){
        v.push_back(s[i] == '1' ? 1 : 0);
    }

    preCal();
    memset(dp, -1, sizeof(dp));

    if(k == 0) return 1;
    LL ans = cal(0, 0, 0);

    if(k == 1){
        ans -= 2;   //eliminate 0 and 1
    }
    return ans;
}

int main(){
    #ifdef DBG_FILE
    freopen("in.txt", "r", stdin);
    #endif

    string s;
    cin >> s >> k;

    cout << getAns(s, k) << endl;

    return 0;
}
