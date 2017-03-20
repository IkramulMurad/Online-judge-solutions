#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

inline LL make_corresponding_value(LL index, LL a, LL n){
    return (n - 1 - (2 * index)) * a;
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n, q;
        scanf("%d %d", &n, &q);

        LL a[n], sum = 0;
        for(int i = 0; i < n; ++i){
            int x;
            scanf("%d", &x);

            a[i] = make_corresponding_value(i, x, n);
            sum += a[i];
        }

        printf("Case %d:\n", t);
        for(int i = 0; i < q; ++i){
            int type;
            scanf("%d", &type);

            if(type){
                printf("%lld\n", sum);
            }
            else{
                int idx, x;
                scanf("%d %d", &idx, &x);

                sum -= a[idx];
                a[idx] = make_corresponding_value(idx, x, n);
                sum += a[idx];
            }
        }
    }

    return 0;
}
