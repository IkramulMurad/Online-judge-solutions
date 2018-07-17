// #define DBG_FILE 1
// #define DBG_DP 2

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;
int n, m;
int allTaken;
LL dp[100][2][11][1024][11];

void printMask(int n){
    if(n == 0) cerr << 0;

    vector <int> v;
    while(n){
        v.push_back(n % 2);
        n /= 2;
    }
    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); ++i){
        cerr << v[i];
    }
}

int set(int n, int pos){
    return (n | (1 << pos));
}

LL cal(int pos, bool start, int lastDigit, int mask, int base){
    if(pos < 0){
        if(mask == allTaken){
            #ifdef DBG_DP
            cerr << "base: " << 1 << endl;
            #endif
            return 1;
        }
        else{
            #ifdef DBG_DP
            cerr << "base: " << 0 << endl;
            #endif
            return 0;
        }
    }

    LL &ret = dp[pos][start][lastDigit][mask][base];
    if(ret != -1){
        #ifdef DBG_DP
        cerr << "mem: " << ret << endl;
        #endif
        return ret;
    }

    ret = 0;
    if(start){
        ret = (ret + cal(pos - 1, start, lastDigit, mask, base)) % mod;

        for(int i = 1; i < base; ++i){
            if(lastDigit == 10 or abs(lastDigit - i) == 1){
                #ifdef DBG_DP
                cerr << "pos: " << pos << ", lastDig: " << i << ", mask: "; printMask(mask); cerr << endl;
                #endif
                ret = (ret +  cal(pos - 1, false, i, set(mask, i), base)) % mod;
            }
        }
    }
    else{
        for(int i = 0; i < base; ++i){
            if(lastDigit == 10 or abs(lastDigit - i) == 1){
                #ifdef DBG_DP
                cerr << "pos: " << pos << ", lastDig: " << i << ", mask: "; printMask(mask); cerr << endl;
                #endif
                ret = (ret +  cal(pos - 1, start, i, set(mask, i), base)) % mod;
            }
        }
    }
    

    return ret;
}

int main(){
    #ifdef DBG_FILE
    freopen("in.txt", "r", stdin);
    #endif

    int tc;
    cin >> tc;

    memset(dp, -1, sizeof(dp));
    for(int t = 1; t <= tc; ++t){
        cin >> n >> m;

        allTaken = (1 << n) - 1;
        cout << cal(m - 1, 2, 10, 0, n) << endl;
    }
}
