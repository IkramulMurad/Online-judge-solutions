//#define DBG_FILE 1
//#define DBG_DP 2
//#define DBG_FUN 3

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
LL dp[9][2][2][10][10];
vector <int> v;

LL cal(int pos, bool start, bool small, int totalSet, int digit){
    if(pos == v.size()){
        #ifdef DBG_DP
        cout << "base: " << totalSet << endl;
        #endif
        return totalSet;
    }

    LL &ret = dp[pos][start][small][totalSet][digit];
    if(ret != -1){
        #ifdef DBG_DP
        cout << "mem: " << ret << endl;
        #endif
        return ret;
    }

    ret = 0;
    int lim = small ? 9 : v[pos];

    if(start){
        for(int i = 1; i <= lim; ++i){
            ret += cal(pos + 1, false, small | (i < v[pos]), totalSet + bool(i == digit), digit);
            #ifdef DBG_DP
            cout << "pos: " << pos << ", digitSet: " << i << ", orgDigit: " << digit << ", ret: " << ret << endl;
            #endif
        }
        ret += cal(pos + 1, start, true, totalSet, digit);
        #ifdef DBG_DP
        cout << endl;
        #endif
    }
    else{
        for(int i = 0; i <= lim; ++i){
            ret += cal(pos + 1, false, small | (i < v[pos]), totalSet + bool(i == digit), digit);
            #ifdef DBG_DP
            cout << "pos: " << pos << ", digitSet: " << i << ", orgDigit: " << digit << ", ret: " << ret << endl;
            #endif
        }
        #ifdef DBG_DP
        cout << endl;
        #endif
    }

    return ret;
}

void processVector(int x){
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

void getAns(LL ans[]){
    for(int i = 0; i < 10; ++i){
        ans[i] = cal(0, 1, 0, 0, i);
        #ifdef DBG_FUN
        cout << "ans: " << ans[i] << endl << endl << endl;
        #endif // DBG_FUN
    }

    #ifdef DBG_FUN
    for(int i = 0; i < 10; ++i){
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    #endif // DBG_FUN
}

void printAns(int a, int b){
    LL ansA[10] = {0};
    LL ansB[10] = {0};

    memset(dp, -1, sizeof(dp));
    processVector(a);
    getAns(ansA);

    memset(dp, -1, sizeof(dp));
    processVector(b);
    getAns(ansB);

    for(int i = 0; i < 10; ++i){
        if(i) cout << " ";
        cout << ansB[i] - ansA[i];
    }
    cout << endl;
}

int main(){
    #ifdef DBG_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int a, b;
    while(cin >> a >> b and (a or b)){
        printAns(a - 1, b);
    }
}
