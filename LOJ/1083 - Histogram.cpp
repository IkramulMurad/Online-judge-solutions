// #define DBG_FILE
// #define DBG_FUN

#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <unistd.h>
using namespace std;

typedef long long LL;
const int mx = 3e4 + 5;
const int sz = (1 << ((int)ceil(log2(mx)) + 1)) + 3;
const LL inf = INT_MAX;
int n;
int a[mx];

struct SegTree{
    int tree[sz];

    void build(int node, int s, int t){
        if(s == t){
            tree[node] = s;
            return;
        }

        int mid = (s + t) / 2;
        int left = node * 2;
        int right = left + 1;

        build(left, s, mid);
        build(right, mid + 1, t);

        tree[node] = a[tree[left]] < a[tree[right]] ? tree[left] : tree[right];
    }

    int query(int node, int s, int t, int i, int j){
        if(i > t or j < s){
            return mx - 1;
        }
        else if(s >= i and t <= j){
            return tree[node];
        }

        int mid = (s + t) / 2;
        int left = node * 2;
        int right = left + 1;

        int p = query(left, s, mid, i, j);
        int q = query(right, mid + 1, t, i, j);

        return a[p] < a[q] ? p : q;
    }
};

SegTree st;

LL maxx(int a, int b, int c){
    return max(max(a, b), c);
}

LL solve(int i, int j){
    #ifdef DBG_FUN
    cout << "i: " << i << ", j: " << j << endl;
    #endif

    if(i > j){
        return 0;
    }

    int mn = st.query(1, 1, n, i, j);

    #ifdef DBG_FUN
    cout << "mn: " << mn << endl;
    #endif

    //usleep(3000000);

    return maxx(solve(i, mn - 1), solve(mn + 1, j), LL(j - i + 1) * a[mn]);
}

LL getAns(){
    st.build(1, 1, n);
    LL ans = solve(1, n);
    return ans;
}

int main(){
    #ifdef DBG_FILE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdin);
    #endif

    int tc;
    cin >> tc;

    a[mx - 1] = inf;
    for(int t = 1; t <= tc; ++t){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        printf("Case %d: %lld\n", t, getAns());
    }

    return 0;
}
