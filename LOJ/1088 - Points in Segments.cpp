#include <bits/stdc++.h>
 
using namespace std;
 
int n,q;
 
int lowBound(int a[],int x){
    int idx=n,mid;
    int hi=n-1,lo=0;
    while(hi>=lo){
        mid=(hi+lo)/2;
        if(a[mid]==x){
            idx=mid;
            hi=mid-1;
        }
        else if(a[mid]>x){
            idx=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return idx;
}
 
int upBound(int a[],int x){
    int idx=0,mid;
    int hi=n-1,lo=0;
    while(hi>=lo){
        mid=(hi+lo)/2;
        if(a[mid]==x){
            idx=mid;
            lo=mid+1;
        }
        else if(a[mid]>x){
            hi=mid-1;
        }
        else{
            idx=mid;
            lo=mid+1;
        }
    }
    return idx;
}
 
int solve(int a[],int x,int y){
    return upBound(a,y)-lowBound(a,x)+1;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
 
        scanf("%d %d",&n,&q);
        int a[n];
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        int x,y;
        printf("Case %d:\n",t);
        for(int i=0;i<q;++i){
            scanf("%d %d",&x,&y);
            int ans=solve(a,x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
