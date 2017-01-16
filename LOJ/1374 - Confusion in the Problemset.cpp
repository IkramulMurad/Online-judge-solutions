#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=1e4+5;
int a[mx];
bitset<mx> isused;
 
bool biSearch(int x, int n){
    int hi=n-1, lo=0, mid;
    while(hi>=lo){
        mid=(hi+lo)>>1;
 
        if(a[mid]==x and !isused[mid]){
            isused[mid]=1;
            return true;
        }
        else if(a[mid]==x and isused[mid]){
            if(mid+1<n and a[mid+1]==x){
                lo=mid+1;
            }
            else if(mid-1>=0 and a[mid-1]==x){
                hi=mid-1;
            }
            else return false;
        }
        else if(a[mid]>x){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return false;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int n;
        scanf("%d",&n);
 
        for(int i=0; i<n; ++i) scanf("%d",a+i);
        sort(a,a+n);
        isused.reset();
 
        int flag=0;
        for(int i=0; i<n; ++i){
            if(biSearch(i,n)){
                continue;
            }
            else if(biSearch(n-i-1,n)){
                continue;
            }
            else{
                flag=1;
                break;
            }
        }
 
        if(flag) printf("Case %d: no\n",t);
        else printf("Case %d: yes\n",t);
    }
    return 0;
}
