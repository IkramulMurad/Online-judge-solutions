#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
const LL mx=46340+5;
bitset<mx> isPrime;
vector<int> primes;
 
void siv(){
    isPrime[0]=isPrime[1]=1;
 
    int sq=sqrt(mx);
    for(LL i=3; i<=sq; i+=2){
        if(!isPrime[i]){
            for(LL j=i*i; j<mx-1; j+=(i<<1)){
                isPrime[j]=1;
            }
        }
    }
 
    //store
    primes.push_back(2);
    for(LL i=3; i<mx-1; i+=2){
        if(!isPrime[i] and i&1){
            primes.push_back(i);
        }
    }
}
 
void factorize(LL a, vector<pair<LL,LL> >& v){
    int sq=sqrt(a);
    for(int i=0; i<primes.size() and primes[i]<=sq; ++i){
        if(primes[i]>a) break;
        int kount=0;
        while(!(a%primes[i])){
            a/=primes[i];
            ++kount;
        }
        if(kount){
            pair<LL,LL> x=make_pair(primes[i],kount);
            v.push_back(x);
        }
    }
    if(a!=1){
        pair<LL,LL> x=make_pair(a,1);
        v.push_back(x);
    }
}
 
int main()
{
    siv();
 
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        LL x,y;
        scanf("%lld",&x);
 
        y=x;
        if(x<0)x*=-1;
        vector<pair<LL,LL> > pFact;
        factorize(x,pFact);
 
        LL ans=2147483647;
        if(y>0){
            for(int i=0; i<pFact.size(); ++i){
                LL prime= pFact[i].first;
                LL mnFreq=pFact[i].second;
                ans=min(ans,mnFreq);
            }
        }
        else{
            for(int i=0; i<pFact.size(); ++i){
                while(!(pFact[i].second&1)){
                    pFact[i].second/=2;
                }
            }
            for(int i=0; i<pFact.size(); ++i){
                LL prime= pFact[i].first;
                LL mnFreq=pFact[i].second;
                ans=min(ans,mnFreq);
            }
        }
 
        printf("Case %d: %lld\n",t,ans);
    }
 
    return 0;
}
