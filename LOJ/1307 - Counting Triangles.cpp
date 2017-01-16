#include <bits/stdc++.h>
 
using namespace std;
int a[2005];
int lowBound(int x,int s,int t){
    int hi=t,lo=s,mid;
    int idx=t+1;
    while(hi>=lo){
        mid=(hi+lo)>>1;
        if(a[mid]>=x){
            idx=mid;
            hi=mid-1;
        }
        else {
            lo=mid+1;
        }
    }
    return idx;
}
int upBound(int x,int s,int t){
    int hi=t,lo=s,mid;
    int idx=t+1;
    while(hi>=lo){
        mid=(hi+lo)>>1;
        if(a[mid]==x){
            idx=mid+1;
            lo=mid+1;
        }
        else if(a[mid]<x){
            lo=mid+1;
        }
        else {
            idx=mid;
            hi=mid-1;
        }
    }
    return idx;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int n;
        scanf("%d",&n);
 
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        sort(a,a+n);
        long long ans=0;
        int prv;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int mx=a[i]+a[j]-1;
                int mn=a[j]-a[i]+1;
                int h=upBound(mx,j+1,n-1);
                int l=lowBound(mn,j+1,n-1);
                prv=h-l;
                ans+=(h-l);
            }
        }
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
