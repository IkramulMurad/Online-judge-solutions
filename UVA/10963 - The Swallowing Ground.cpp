#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,x,y;
        scanf("%d",&n);

        int d;
        bool no=0;
        for(int i=0; i<n; ++i){
            scanf("%d %d",&x,&y);
            if(i==0){
                d=x-y;
            }
            if(d!=x-y){
                no=1;
            }
        }
        if(no) printf("no\n");
        else printf("yes\n");
        if(tc) printf("\n");
    }
    return 0;
}
