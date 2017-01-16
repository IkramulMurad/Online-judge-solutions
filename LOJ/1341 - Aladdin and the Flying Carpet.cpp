#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
const int mx=1e6+5;
vector<int> prime;
 
void siv(){
    bitset<mx> isprime;
    isprime[0]=isprime[1]=1;
 
    for(int i=3; i<=sqrt(mx); i+=2){
        if(isprime[i]==0){
            for(int j=i*i; j<mx-1; j+=i*2){
                isprime[j]=1;
            }
        }
    }
    //store
    prime.push_back(2);
    for(int i=3; i<mx-1; i+=2){
        if(isprime[i]==0){
            prime.push_back(i);
        }
    }
}
 
LL numDiv(LL n){
 
    LL ans=1;
    for(int i=0; i<prime.size() and prime[i]<=sqrt(n); i++){
        int kount=0;
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                kount++;
            }
 
            ans*=(kount+1);
        }
        if(n==1) break;
    }
    if(n!=1) ans<<=1;
    return ans;
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
    if(neg) x*=-1;
}
 
int main()
{
    siv();
    int tc,t=1;
    fastIn(tc);
    while(tc--){
        LL a,b;
        fastIn(a); fastIn(b);
 
        if(b>=sqrt(a)){
            printf("Case %d: 0\n",t++);
            continue;
        }
 
        LL ans=numDiv(a)>>1;
 
        for(int i=1; i<b; i++){
            if(a%i==0) ans--;
        }
 
        printf("Case %d: %lld\n",t++,ans);
    }
    return 0;
}
