#include <bits/stdc++.h>
 
using namespace std;
 
int a[1005];
int binSearch(int x,int l,int h){
    int mid,idx=h+1;
    while(h>=l){
        mid=(h+l)>>1;
        if(a[mid]==x) return mid;
        else if(a[mid]>x){
            idx=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return idx-1;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int n,m;
        scanf("%d %d",&n,&m);
        int mx=0;
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
            mx=max(mx,a[i]);
        }
        printf("Case %d: ",t);
        if(m>=n) printf("%d\n",mx);
        else{
            for(int i=1;i<n;++i){
                a[i]+=a[i-1];
            }
            int ans=mx;
            int h=a[n-1],l=max(mx,a[n-1]/m);
            int mid;
            int con,hi;
            while(h>=l){
                mid=(h+l)>>1;
                con=0;hi=0;
                int p=0;
                for(int i=0;i<n;){
                    i=binSearch(p+mid,i,n-1);
                    ++con;
                    hi=max(hi,a[i]-p);
                    p=a[i];
                    if(i==n-1) break;
                }
                if(con==m){
                    ans=hi;
                    h=mid-1;
                }
                else if(con>m){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
