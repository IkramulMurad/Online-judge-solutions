#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("out.txt","w",stdout);
    int n,m,c,t=0;
    while(cin>>n>>m>>c and n and m and c){
        bool sw[n]={0};
        int a[n];

        for(int i=0; i<n; ++i) cin>>a[i];

        int ans=0,step=0;
        for(int i=0; i<m; ++i){
            int x;
            cin>>x;
            --x;

            if(!sw[x]){
                step+=a[x];
                sw[x]=1;
            }
            else{
                step-=a[x];
                sw[x]=0;
            }
            ans=max(ans,step);
        }
        printf("Sequence %d\n",++t);
        if(ans>c) printf("Fuse was blown.\n");
        else{
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n",ans);
        }
        printf("\n");
    }
    return 0;
}
