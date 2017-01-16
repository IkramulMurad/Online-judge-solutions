#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long LL;
typedef unsigned int UL;
const int mx=1e8+5;
const int rng=1000005;
const LL m=4294967296;
vector<int> prime;
bitset<mx> isprime;
LL MulPrime[rng];
 
void fastIn(int& n){
    n=0;
    register int c;
    bool flag=0;
 
    c=getchar();
    if(c=='-'){
        flag=1;
        c=getchar();
    }
    while(c>47 and c<58){
        n=(n<<1)+(n<<3)+c-48;
        c=getchar();
    }
    if(flag){
        n*=-1;
    }
}
 
 
void siv(){
    int sq=sqrt(mx);
 
    isprime[0]=isprime[1]=1;
    prime.push_back(2);
    for(int i=3; i<=sq; i+=2){
        if(!isprime[i]){
            prime.push_back(i);
            for(int j=i*i; j<mx-2; j+=(i<<1)){
                isprime[j]=1;
            }
        }
    }
 
    bitset<rng> isUsed;
    isUsed[0]=isUsed[1]=1;
    MulPrime[0]=1;
    MulPrime[1]=2;
    for(int i=3; i<mx-2; i+=2){
        int index=i/100+1;
        if(!isUsed[index]){
            isUsed[index]=1;
            MulPrime[index]=MulPrime[index-1];
        }
        if(!isprime[i] and i&1){
            MulPrime[index]=(MulPrime[index]*i)%m;
        }
    }
}
 
LL bigmod(LL b,LL p){
 
    LL res=1;
    while(p>0){
        if(p&1){
            res=(res*b)%m;
            --p;
            continue;
        }
        p=(p>>1);
        b=(b*b)%m;
    }
 
    return res;
}
 
LL getLCM(int n){
    if(n==2) return 2;
    if(n==3) return 6;
    int index=n/100;
    //if(n%100==0) --index;
 
    int start=n-n%100;
    LL ans=MulPrime[index];
    for(LL i=start; i<=n; ++i){
        if(i==2) ans=(ans*i)%m;
        if(!isprime[i] and i&1)
            ans=(ans*i)%m;
    }
 
    int sqn=sqrt(n);
 
    for(int i=0; i<prime.size(); ++i){
 
        if(prime[i]>sqn) break;
        int p=0;
        LL x=prime[i];
        while(x<=n){
            ++p;
            x*=prime[i];
        }
        ans=(ans*bigmod(prime[i],p-1))%m;
    }
 
    return ans;
}
 
int main()
{
    siv();
 
    int tc;
    fastIn(tc);
    for(int t=1; t<=tc; ++t){
 
        int n;
        fastIn(n);
 
        LL ans=getLCM(n);
        printf("Case %d: %llu\n",t,ans);
    }
 
    return 0;
}
