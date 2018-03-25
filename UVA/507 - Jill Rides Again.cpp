#include <bits/stdc++.h>
using namespace std;

int ffirst, flast;

bool possible(int n, int a[]){
    int mx, mxHere, first, last, dmyFirst;
    mx = mxHere = dmyFirst = 0;
    first = last = -1;

    for(int i = 0; i < n; ++i){
        mxHere += a[i];

        if(mxHere > mx){
            mx = mxHere;
            first = dmyFirst;
            last = i + 1;

            ffirst = first;
            flast = last;
        }
        if(mxHere == mx){
            first = dmyFirst;
            last = i + 1;

            if(last - first > flast - ffirst){
                ffirst = first;
                flast = last;
            }
        }
        if(mxHere < 0){
            mxHere = 0;
            dmyFirst = i + 1;
        }
    }

    if(first == -1) return false;
    return true;
}

int main()
{
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n - 1; ++i) cin >> a[i];

        if(possible(n - 1, a)){
            printf("The nicest part of route %d is between stops %d and %d\n", t, ffirst + 1, flast + 1);
        }
        else printf("Route %d has no nice parts\n", t);
    }

    return 0;
}
