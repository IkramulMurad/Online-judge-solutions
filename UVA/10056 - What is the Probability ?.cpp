#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double calculate(int n, int s, double ps, double pu){
    if(ps == 0) return 0;
    return ps * pow(pu, s - 1)/(1 - pow(pu, n));
}

int main()
{
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int n, s;
        double ps, pu;

        cin >> n >> ps >> s;
        pu = 1 - ps;

        double ans = calculate(n, s, ps, pu);
        printf("%.4f\n", ans);
    }

    return 0;
}
