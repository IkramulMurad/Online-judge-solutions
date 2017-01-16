#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const ll mx=1e6+5;
const ll mod=1e6+3;
const ll lim=1e6;
 
ll fact[mx];
 
void calc(){
    fact[0]=1;
    for(ll i=1;i<=lim;i++){
        fact[i]=((fact[i-1])%mod * i%mod )%mod;
    }
}
 
ll bigMod(ll a,ll b){
    if(b==0) return 1;
    ll ans=bigMod(a,b/2)%mod;
    ans=(ans*ans)%mod;
    if(b%2){
       ans=((a%mod)*ans)%mod;
       return ans;
    }
    return ans;
}
 
ll ncrMod(ll n,ll k){
    long long num=fact[n]%mod;
    ll a=bigMod(fact[k],mod-2)%mod;
    ll b=bigMod(fact[n-k],mod-2)%mod;
    long long den=(a * b)%mod;
    ll ans=(num*den)%mod;
    return ans;
}
 
int main()
{
    calc();
    ll tc;
    scanf("%lld",&tc);
    for(ll t=1;t<=tc;t++){
        ll n,k;
        scanf("%lld %lld",&n,&k);
        ll x=ncrMod(n,k);
        printf("Case %lld: %lld\n",t,x);
    }
    return 0;
}
