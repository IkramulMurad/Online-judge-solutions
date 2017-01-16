#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
const int mx=1e6+5;
vector<int> primes;
bitset<mx> status;
 
LL lcm(LL a,LL b){
    LL g=__gcd(a,b);
    return (a*b)/g;
}
 
void siv(){
    int sq=sqrt(mx);
    status[0]=status[1]=1;
    for(int i=3;i<=sq;i+=2){
        if(!status[i]){
            for(int j=i*i;j<mx-2;j+=(i<<1)){
                status[j]=1;
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<mx-2;i+=2){
        if(!status[i]){
            primes.push_back(i);
        }
    }
}
 
void primeFactorize(LL a,vector<pair<LL,LL> >& vec){
    LL sq=sqrt(a);
    for(int i=0;i<primes.size();++i){
        if(primes[i]>sq) break;
        int kount=0;
        while(a%primes[i]==0){
            a/=primes[i];
            ++kount;
        }
        if(kount){
            pair<LL,LL> x=make_pair(primes[i],kount);
            vec.push_back(x);
        }
    }
    if(a!=1){
        pair<LL,LL> x=make_pair(a,1);
        vec.push_back(x);
    }
}
 
int main()
{
    siv();
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        LL a,b,c,labc;
        scanf("%lld %lld %lld",&a,&b,&labc);
 
        if(labc%lcm(a,b)){
            printf("Case %d: impossible\n",t);
            continue;
        }
        //prime factorize
        vector<pair<LL,LL> > vec;
        primeFactorize(labc,vec);
 
        c=labc;
 
        for(int i=0;i<vec.size();++i){
            LL prime=vec[i].first;
            LL freq=vec[i].second;
            for(int j=0;j<freq;++j){
                if(lcm(lcm(a,c/prime),b)==labc){
                    c/=prime;
                }
            }
        }
        printf("Case %d: %lld\n",t,c);
    }
    return 0;
}
