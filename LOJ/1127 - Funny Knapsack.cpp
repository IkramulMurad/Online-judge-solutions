#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
int upBound(LL x, vector<LL>& v){
    int hi=v.size()-1,lo=0,mid;
    int idx=v.size();
 
    while(hi>=lo){
        mid=(hi+lo)>>1;
        if(v[mid]==x){
            idx=mid+1;
            lo=mid+1;
        }
        else if(v[mid]>x){
            idx=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return idx;
}
 
bool check(int x, int i){
    return bool(x&(1<<i));
}
 
void makeSum(vector<LL>& v, int a[], int bitsNum){
    int rng=1<<bitsNum;
    for(int i=0; i<rng; ++i){
        LL x=0;
        for(int j=0; j<bitsNum; ++j){
            if(check(i,j)) x+=a[j];
        }
        v.push_back(x);
    }
    /*for(int i=0; i<v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;*/
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        LL n,w;
        scanf("%lld %lld",&n,&w);
 
        if(n==1){
            int x;
            scanf("%d",&x);
            int ans=1;
            if(x<=w) ans=2;
            printf("Case %d: %d\n",t,ans);
            continue;
        }
 
        int mid1=n/2, mid2=(n-mid1);
        int a1[mid1],a2[mid2];
 
        for(int i=0; i<n; ++i){
            if(i<mid1) scanf("%d",a1+i);
            else scanf("%d",a2+i-mid1);
        }
 
        vector<LL> p1,p2;
 
        makeSum(p1,a1,mid1);
        makeSum(p2,a2,mid2);
 
        sort(p2.begin(),p2.end());
        LL ans=0;
 
        for(int i=0; i<p1.size(); ++i){
            if(p1[i]<=w)
                ans+= upBound(w-p1[i],p2);
        }
 
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
