#include <bits/stdc++.h>

using namespace std;

const int mx=5e4+5;
int a[mx];
int l,h;

int lowBound(int x,int n){
    int idx=mx,mid;
    int hi=n,lo=0;
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

int upBound(int x,int n){
    int idx=-1,mid;
    int hi=n,lo=0;
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

void solve(int x,int n){
    l=upBound(x-1,n-1);
    h=lowBound(x+1,n-1);
}

int main()
{
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        int q,height;
        scanf("%d",&q);
        for(int i=0;i<q;++i){
            scanf("%d",&height);
            solve(height,n);
            if(l<0) printf("X ");
            else printf("%d ",a[l]);
            if(h>=n) printf("X");
            else printf("%d",a[h]);
            printf("\n");
        }
    }
    return 0;
}
