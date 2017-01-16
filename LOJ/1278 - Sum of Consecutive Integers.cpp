#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
const int mx=1e7+5;
vector<int> prime;
bitset<mx> isprime;
 
void siv(){
    int sq=sqrt(mx);
 
    isprime[0]=isprime[1]=1;
    for(int i=3; i<=sq; i+=2){
        if(!isprime[i] and i&1){
            for(int j=i*i; j<mx-1; j+=(i<<1)){
                isprime[j]=1;
            }
        }
    }
    //store
    prime.push_back(2);
    for(int i=3; i<mx-1; i+=2){
        if(!isprime[i]){
            prime.push_back(i);
        }
    }
}
 
template<class T>
void fastIn(T& x){
    x=0;
    register int c;
    bool neg=0;
 
    c=getchar();
    if(c=='-'){
        neg=1;
        c=getchar();
    }
    while(c>47 and c<58){
        x=(x<<1)+(x<<3)+c-48;
        c=getchar();
    }
    if(neg)x*=-1;
}
 
int main()
{
    siv();
    int tc;
    fastIn(tc);
    for(int t=1; t<=tc; ++t){
        vector<pair<int,int> > v;
        LL n;
        fastIn(n);
 
        if(n<=2){
            printf("Case %d: 0\n",t);
            continue;
        }
 
        int sqn=sqrt(n);
        for(int i=0; i<prime.size() and prime[i]<=sqn; ++i){
            int kount=0;
            while(n%prime[i]==0){
                n/=prime[i];
                ++kount;
            }
            if(kount and prime[i]&1){
                v.push_back(make_pair(prime[i],kount+1));
            }
        }
 
        if(n!=1){
            v.push_back(make_pair(n,2));
        }
 
        LL ans=1;
        for(int i=0; i<v.size(); ++i){
            ans*=v[i].second;
        }
 
 
        printf("Case %d: %lld\n",t,ans-1);
    }
    return 0;
}
