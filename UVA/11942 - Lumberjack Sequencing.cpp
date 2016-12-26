#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n){
        printf("Lumberjacks:\n");
        for(int i=0; i<n; ++i){
            int a[10],sorted=1;
            for(int j=0; j<10; ++j) cin>>a[j];

            if(a[0]>a[1]){
                for(int j=1; j<10; ++j){
                    if(a[j]>a[j-1]) sorted=0;
                }
            }
            else{
                for(int j=1; j<10; ++j){
                    if(a[j]<a[j-1]) sorted=0;
                }
            }

            sorted? printf("Ordered\n"): printf("Unordered\n");
        }
    }
    return 0;
}
