// #define DBG_FILE
// #define DBG_FUN
// #define DBG_DP

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long LL;
LL dp[19][2][2];
vector <int> v;

void procesVector(LL x);
LL getAns(LL n);
LL cal(int pos, bool small, bool lastDigitOne);
LL lowBound(LL lo, LL hi, LL n);

int main(){
    #ifdef DBG_FILE
    freopen("in.txt", "r", stdin);
    #endif

    LL n;
    while(cin >> n){
        cout << getAns(n) << endl;
    }

    return 0;
}

LL getAns(LL n){
    LL lo = n;
    LL hi = 2 * lo;
    
    while(true){
        memset(dp, -1, sizeof(dp));
        procesVector(hi);
        LL k = cal(0, 0, 0) - 1;

        if(k >= n){
            break;
        }
        else{
            lo = hi;
            hi *= 2;
        }
    }

    #ifdef DBG_FUN
    cout << "hi: " << hi << ", lo: " << lo << endl;
    #endif
    
    LL ans = 0;
    ans = lowBound(lo, hi, n);
    return ans;
}

LL cal(int pos, bool small, bool lastDigitOne){
    if(pos == v.size()){
        return 1;
    }

    LL &ret = dp[pos][small][lastDigitOne];
    if(ret != -1){
        return ret;
    }

    ret = 0;
    int lim = small ? 9 : v[pos];

    for(int i = 0; i <= lim; ++i){
        if(i == 4 or (lastDigitOne and i == 3)) continue;
        ret += cal(pos + 1, small | (i < v[pos]), (i == 1));
    }

    return ret;
}

LL lowBound(LL lo, LL hi, LL n){
    LL ret = -1;

    while(lo <= hi){
        LL mid = lo + (hi - lo) / 2;
        
        procesVector(mid);
        memset(dp, -1, sizeof(dp));
        LL k = cal(0, 0, 0) - 1;

        #ifdef DBG_FUN
        cout << "hi: " << hi << ", lo: " << lo << ", mid: " << mid << ", k: " << k << endl;
        #endif

        if(k == n){
            ret = mid;
            hi = mid - 1;
        }
        else if(k > n){
            hi = mid - 1;
        }
        else if(k < n){
            lo = mid + 1;
        }
    }
    return ret;
}


void procesVector(LL x){
    v.clear();
    if(x == 0){
        v.push_back(0);
        return;
    }

    while(x){
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
}
