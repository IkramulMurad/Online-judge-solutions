#include <bits/stdc++.h>
 
using namespace std;
 
int a[1005];
int flag=0;
 
int read(int mx,int n){
    for(int i=0;i<=n;++i){
        scanf("%d",a+i);
        mx=max(mx,a[i]);
        if(i>0) a[i]+=a[i-1];
    }
    return mx;
}
 
int binSearch(int x,int l,int h){
    int mid,idx=h+1;
    while(h>=l){
        mid=(h+l)>>1;
        if(a[mid]==x){
            return mid;
        }
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
 
int mainSearch(int n,int mx,int k){
    int hi=a[n],lo=mx,mid;
    int idx;
    while(hi>=lo){
        mid=(hi+lo)>>1;
        int prv=0,camp=0;
        for(int i=0;;){
            i=binSearch(prv+mid,i,n);
            prv=a[i];
            ++camp;
            if(i==n) break;
        }
        if(camp<=k+1){
            if(camp==k+1)flag=1;
            idx=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return idx;
}
 
int getMax(vector<int>& anz){
    int cost=0;
    for(int i=0;i<anz.size();++i){
        cost=max(cost,anz[i]);
    }
    return cost;
}
 
vector<int> reArrange(int n,vector<int>& anz){
    int total=0,j=n;
    for(int i=anz.size()-1; i>=0; --i,--j){
        if(anz[i]==0){
            total+=a[j]-a[j-1];
            anz[i]=a[j]-a[j-1];
        }
        else{
            if(anz[i]>total){
                anz[i]-=total;
                total=0;
            }
            else{
                if(j>0){
                    total-=(anz[i]-(a[j]-a[j-1]));
                    anz[i]=a[j]-a[j-1];
                }
            }
            if(total==0) break;
        }
        if(i==0){
            if(j>0)anz[0]+=a[j-1];
            else anz[0]-=total;
        }
    }
    return anz;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
 
        int n,k,mx=0;
        scanf("%d %d",&n,&k);
        mx=read(mx,n);
        flag=0;
        vector<int> ans(k+1);
        int rng=mainSearch(n,mx,k);
        int p=0;
        for(int i=0,j=0;;++j){
            i=binSearch(p+rng,i,n);
            ans[j]=(a[i]-p);
            p=a[i];
            if(i==n) break;
        }
        if(!flag){
            ans=reArrange(n,ans);
        }
        int cost=getMax(ans);
        printf("Case %d: %d\n",t,cost);
        for(int i=0;i<ans.size();++i){
            printf("%d\n",ans[i]);
        }
 
    }
    return 0;
}
