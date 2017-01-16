#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=5e6+5;
const int lim=5e6;
bitset<mx> prime;
unsigned long long phi[mx];
void sivphi(){
    int sq=sqrt(lim);
    prime.set();
    for(int i=1;i<=lim;i++){
        phi[i]=i;
    }
    for(int i=4;i<=lim;i+=2){
        prime[i]=0;
        phi[i]/=2;
    }
    for(int i=3;i<=lim;i+=2){
        if(prime[i]){
            phi[i]=i-1;
            for(int j=i*2;j<=lim;j+=i){
                prime[j]=0;
                phi[j]-=phi[j]/i;
            }
        }
    }
 
}
 
 
int main()
{
    sivphi();
    for(int i=3;i<=lim;i++){
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int l,r;
        scanf("%d %d",&l,&r);
        unsigned long long ans=phi[r]-phi[l-1];
        printf("Case %d: %llu\n",t,ans);
    }
    return 0;
}
