#include <bits/stdc++.h>
 
using namespace std;
 
const int mod=1e9+7;
vector<int> prime;
 
void siv()
{
    const int rt=65540+3;
    bitset<rt> isPrime;
    int sq=sqrt(rt);
    isPrime.set();
    isPrime[0]=isPrime[1]=0;
    for(int i=3; i<=sq; i+=2)
    {
        if(isPrime[i]){
            for(int j=i*i; j<rt; j+=i+i)
            {
                isPrime[j]=0;
            }
        }
    }
    prime.push_back(2);
    for(int i=3; i<rt; i+=2)
    {
        if(isPrime[i]){
            prime.push_back(i);
        }
    }
}
long long  bigMod ( long long a, long long p)
{
    if (p==0) return 1;
    if (p%2)
    {
        return ((a%mod)*(bigMod(a,p-1)))%mod;
    }
    else
    {
        long long c=bigMod(a,p/2);
        return ((c%mod)*(c%mod))%mod;
    }
}
 
long long solve(long long n,long long m){
    int sz=prime.size();
    long long ans=1;
    for(int i=0;i<sz && prime[i]*prime[i]<=n; i++){
        long long kount=0;
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                kount++;
            }
            kount*=m;
            long long x=((bigMod(prime[i],kount+1)+(-1+mod))%mod);
            long long y=bigMod(prime[i]-1,mod-2);
            ans*=(x*y)%mod;
            ans%=mod;
        }
    }
    if(n!=1){
        long long x=((bigMod(n,m+1)+(-1+mod))%mod);
        long long y=bigMod(n-1,mod-2);
        ans*=(x*y)%mod;
        ans%=mod;
    }
    return ans;
}
int main()
{
    siv();
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        long long n,m;
        scanf("%lld %lld",&n,&m);
        printf("Case %d: %lld\n",t,solve(n,m));
    }
    return 0;
}
