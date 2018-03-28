#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mx = 12;
LL dp[mx][2][2][mx];
vector <int> num;
int n;

LL cal(int pos, bool start, bool small, int zeros){
    if(pos == n) return zeros;

    LL &ret = dp[pos][start][small][zeros];
    if(ret != -1) return ret;

    int lim = small ? 9 : num[pos];

    int i;
    ret = 0;
    if(!start){
        for(i = 0; i <= lim; ++i){
            ret += cal(pos + 1, 0, small | (i < num[pos]), (i == 0) + zeros);
        }
    }
    else{
        for(i = 1; i <= lim; ++i){
            ret += cal(pos + 1, 0, small | (i < num[pos]), (i == 0) + zeros);
        }
        ret += cal(pos + 1, 1, 1, 0);
    }

    return ret;
}

LL solve(LL x){
    if(x < 0) return 0;
    if(x <= 9) return 1;

    num.clear();
    while(x){
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    n = num.size();

    memset(dp, -1, sizeof(dp));
    return 1 + cal(0, 1, 0, 0);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        LL l, r;
        cin >> l >> r;
        LL ans = solve(r);
        ans -= solve(l - 1);
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}


//*************Implementation solution*****************//
// #include <bits/stdc++.h>
 
// using namespace std;
 
// long long getAns(long long x){
//     if(x<0) return 0;
//     long long ans=x/10+1,y=x,den=10,rng,q,r;
//     x/=10;
//     while(x>=10){
//         rng=den;
//         den*=10;
//         q=y/den;
//         r=y%den;
//         if(r<rng)
//             ans+=((q-1)*rng)+(r+1);
//         else
//             ans+=(q*rng);
//         x/=10;
//     }
//     return ans;
// }
 
// int main()
// {
//     int tc;
//     scanf("%d",&tc);
//     for(int t=1;t<=tc;++t){
//         long long m,n;
//         scanf("%lld %lld",&m,&n);
//         long long ans=getAns(n)-getAns(m-1);
//         printf("Case %d: %lld\n",t,ans);
//     }
//     return 0;
// }
