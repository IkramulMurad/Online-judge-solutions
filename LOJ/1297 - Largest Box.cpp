#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    //freopen("in", "r", stdin);
 
    int tc;
    scanf("%d", &tc);
 
    for(int t = 1; t <= tc; ++t){
        double l, w;
        scanf("%lf %lf", &l, &w);
 
        //process
        //volume = l * w * h
        //so, volume = (l - 2x) * (w - 2x) * x
        //do differentiation for maximum
        //use quadratic equation to solve
        double x1, x2;
        x1 = ((w + l) + sqrt(w * w - w * l + l * l)) / 6;
        x2 = ((w + l) - sqrt(w * w - w * l + l * l)) / 6;
 
        double ans1, ans2;
        ans1 = (w - 2 * x1) * (l - 2 * x1) * x1;
        ans2 = (w - 2 * x2) * (l - 2 * x2) * x2;
 
        printf("Case %d: %.8f\n", t, max(ans1, ans2));
    }
 
    return 0;
}
