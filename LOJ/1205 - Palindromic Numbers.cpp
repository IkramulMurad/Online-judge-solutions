#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL dp[20][2][2][20];
vector <int> num;
int sz;

LL cal(int pos, bool start, bool small, int upto){
    if(start and pos == num.size()) return 0;
    if(pos == upto) return 1;

    LL &ret = dp[pos][start][small][upto];
    if(ret != -1) return ret;

    ret = 0;
    int lim = small ? 9 : num[pos];

    if(!start){
        for(int i = 0; i <= lim; ++i){
            ret += cal(pos + 1, 0, small | (i < num[pos]), upto);
        }
    }
    else{
        for(int i = 1; i <= lim; ++i){
            ret += cal(pos + 1, 0, small | (i < num[pos]), upto);
        }
        ret += cal(pos + 1, 1, 1, (sz + 1 + pos + 1) / 2);
    }

    return ret;
}

LL solve(LL n){
    if(n < 0) return 0;
    if(n == 0) return 1;

    if(n % 10 == 0) --n;

    num.clear();
    while(n){
        num.push_back(n % 10);
        n /= 10;
    }
    reverse(num.begin(), num.end());

    sz = num.size();
    for(int i = sz - 1; i >=  sz / 2; --i){
        if(num[i] < num[sz - i - 1]){
            //find prev non zero
            int idx = i - 1;
            while(!num[idx]){
                --idx;
            }

            //decrement non zero and set all next pos to 9
            num[idx]--;
            for(int j = idx + 1; j < sz; ++j){
                num[j] = 9;
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    return 1 + cal(0, 1, 0, (sz + 1) / 2);
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        LL l, r;
        cin >> l >> r;

        LL ans = solve(max(l, r)) - solve(min(l, r) - 1);
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
