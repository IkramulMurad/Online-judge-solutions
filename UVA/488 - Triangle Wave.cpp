#include <bits/stdc++.h>

using namespace std;

void prnt(int n){
    for(int i=1; i<=n; ++i){
        for(int j=0; j<i; ++j){
            printf("%d",i);
        }
        printf("\n");
    }
    for(int i=n-1; i>=1; --i){
        for(int j=0; j<i; ++j){
            printf("%d",i);
        }
        printf("\n");
    }
}

void solve(int in, int out){
    for(int i=0; i<out; ++i){
        prnt(in);
        if(i!=out-1) printf("\n");
    }
}

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int a,f;
        scanf("%d %d",&a,&f);
        if(t!=1) printf("\n");
        solve(a,f);

    }
    return 0;
}
