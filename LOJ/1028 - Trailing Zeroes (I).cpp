#include <bits/stdc++.h>
 
using namespace std;
 
const long long mx=1e12+5;
const int mm=1e6+5;
bitset<mm> isPrime;
vector<int> prime;
vector<int>::iterator it;
 
void siv()
{
 
    int sq=sqrt(mm);
    isPrime.set();
    isPrime[0]=0;
    isPrime[1]=0;
    prime.push_back(2);
    for(int i=3; i<=sq+1; i+=2)
    {
        if(isPrime[i]){
            for(int j=i*i; j<=mm; j+=i+i)
            {
                isPrime[j]=0;
            }
        }
    }
    for(int i=3; i<mm; i+=2)
    {
        if(isPrime[i]){
            prime.push_back(i);
        }
    }
}
int main()
{
    //freopen("out.txt","w",stdout);
    siv();
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        long long n;
        scanf("%lld",&n);
        long long ans=1;
        int sz=prime.size();
        for(int i=0;i<sz && prime[i]*prime[i]<=n;i++){
            int x=prime[i];
            int kount=1;
            while(n%x==0){
                n/=x;
                kount++;
            }
            ans*=kount;
        }
        if(n!=1){
            ans*=2;
        }
        printf("Case %d: %lld\n",t,ans-1);
    }
    return 0;
}
