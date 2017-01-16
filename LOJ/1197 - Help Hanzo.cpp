#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
const int mx=46340+5;
const int rng=4792;
int primes[rng];
 
void fastIn(int& x){
    x=0;
    register int c;
    bool neg=false;
 
    c=getchar();
    if(c=='-'){
        neg=true;
        c=getchar();
    }
    while(c>47 and c<58){
        x=(x<<1)+(x<<3)+(c-48);
        c=getchar();
    }
 
    if(neg) x*=-1;
}
 
void siv(){
    bitset<mx> isprime;
    isprime[0]=isprime[1]=1;
 
    int sq=sqrt(mx);
    for(int i=3; i<=sq; i+=2){
        if(!isprime[i]){
            for(int j=i*i; j<mx-2; j+=(i<<1)){
                isprime[j]=1;
            }
        }
    }
    //store
    int k=0;
    primes[k]=2;
    for(int i=3; i<mx-2; i+=2){
        if(!isprime[i]){
            primes[++k]=i;
        }
    }
}
 
int segmentSiv(int a,int b){
    if(b<2) return 0;
    if(a<2) a=2;
    int kount=0;
    int sqb=sqrt(b);
    bitset<100005> isprime;
 
    for(int i=1; i<rng and primes[i]<=sqb ; ++i){
        LL j=(a/primes[i]);
        j*=primes[i];
 
        if(j<a) j+=primes[i];
        if(j==primes[i]) j+=primes[i];
        if(!(j&1)){
            isprime[j-a]=1;
            j+=primes[i];
        }
 
        for(; j<=b; j+=(primes[i]<<1)){
            isprime[j-a]=1;
        }
    }
 
    if(a==2)++kount;
    for(int i=a; i<=b; ++i){
 
        if(!isprime[i-a] and i&1) ++kount;
    }
 
    return kount;
}
 
int main()
{
 
    siv();
    int tc;
    fastIn(tc);
    for(int t=1; t<=tc; ++t){
        int a,b;
        fastIn(a);
        fastIn(b);
 
        int ans= segmentSiv(a,b);
 
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
