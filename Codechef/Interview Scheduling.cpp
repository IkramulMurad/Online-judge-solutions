#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
const int mx = 105;
const int mxt = 24 * 60 + 5;
vector <ii> v;
int dp[mx][mxt];

int cal(int i, int timePassed){
    if(i == v.size()){
        return 0;
    }

    int &ret = dp[i][timePassed];
    if(ret != -1){
        return ret;
    }

    int p = 0, q = 0;

    if(timePassed + v[i].second <= v[i].first){
        p = 1 + cal(i + 1, timePassed + v[i].second);
    }
    q = cal(i + 1, timePassed);

    ret = max(p, q);
    return ret;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int n;
        cin >> n;

        int duration[n], remaining[n];
        for(int i = 0; i < n; ++i) cin >> duration[i];
        for(int i = 0; i < n; ++i) cin >> remaining[i];
        
        v.clear();
        int canGo = 0;
        for(int i = 0; i < n; ++i){
            if(remaining[i] != -1){
                v.push_back({remaining[i] - 30, duration[i]});
            }
            else{
                canGo++;
            }
        }

        sort(v.begin(), v.end());
        memset(dp, -1, sizeof(dp));

        canGo += cal(0, 0);
        printf("Case %d: %d\n", t, n - canGo);
    }

    return 0;
}
