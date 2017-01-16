#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
const int mx = 1e6+10;
bitset<mx> isprime;
 
void siv(){
    for(int i=2; i<mx ; ++i){
        if(!isprime[i]){
            for(int j=i+i; j<mx; j+=i)
                isprime[j]=1;
        }
    }
 
}
 
int main(){
    siv();
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        LL ans=0;
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; ++i){
            int x;
            scanf("%d",&x);
            for(int j=x+1; ; ++j){
                if(isprime[j]==0){
                    ans+=j;
                    break;
                }
            }
        }
        printf("Case %d: %lld Xukha\n",t,ans);
    }
    return 0;
}
