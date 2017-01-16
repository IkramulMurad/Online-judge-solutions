#include <bits/stdc++.h>
 
using namespace std;
 
int a[101];
 
int find(int x, int n){
    for(int i=x+1; i<=n; ++i){
        if(a[i]==x) return i;
    }
    return n;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int n;
        scanf("%d",&n);
 
        for(int i=1; i<=n; ++i) scanf("%d",a+i);
 
        int ans=0;
        for(int i=1; i<=n; ++i){
            if(a[i]!=i){
                int x=find(i,n);
 
                int temp=a[i];
                a[i]=a[x];
                a[x]=temp;
 
                ++ans;
                /*for(int j=1; j<=n; ++j) cout<<a[j]<<" ";
                cout<<endl;*/
            }
        }
 
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
