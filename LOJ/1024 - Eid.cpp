#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long LL;
const int mx=1e4+5;
bitset<mx> bt;
vector<int> v;
 
void siv(){
    int sq=sqrt(mx);
    bt[0]=bt[1]=1;
    for(int i=3;i<=sq;i+=2){
        if(!bt[i]){
            for(int j=i*i;j<mx-1;j+=(i<<1)){
                bt[j]=1;
            }
        }
    }
    v.push_back(2);
    for(int i=3;i<mx-1;i+=2){
        if(!bt[i])v.push_back(i);
    }
}
 
string multiply(string a,int b){
    string ans;
    int carry=0;
    for(int i=a.size()-1;i>=0;--i){
        int dig=a[i]-48;
        int d=dig*b+carry;
        carry=d/10;
        d%=10;
        char c='0'+d;
        ans.push_back(c);
    }
    while(carry){
        char c='0'+carry%10;
        ans.push_back(c);
        carry/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
 
}
 
int main()
{
    siv();
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
 
        //prime factorization
        vector<int> primes;
        bitset<mx> isUsed;
        int freq[mx];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<n;++i){
            int x=a[i];
            int sq=sqrt(x);
            if(!bt[x] and x&1){
                freq[x]=max(freq[x],1);
                if(!isUsed[x]){
                    isUsed[x]=1;
                    primes.push_back(x);
                }
                continue;
            }
            for(int j=0;j<v.size();++j){
                if(v[j]>sq) break;
                int kount=0;
                while(x%v[j]==0){
                    ++kount;
                    x/=v[j];
                }
                if(kount){
                    freq[v[j]]=max(freq[v[j]],kount);
                    if(!isUsed[v[j]]){
                        isUsed[v[j]]=1;
                        primes.push_back(v[j]);
                    }
                }
                if(!bt[x] and x&1){
                    freq[x]=max(freq[x],1);
                    if(!isUsed[x]){
                        isUsed[x]=1;
                        primes.push_back(x);
                    }
                    break;
                }
            }
        }
 
        //producing answer
        string ans="1";
        for(int i=0;i<primes.size();++i){
            int prime=primes[i];
            int frq=freq[prime];
 
            for(int i=0;i<frq;++i){
                ans=multiply(ans,prime);
            }
        }
 
        printf("Case %d: ",t);
        cout<<ans;
        printf("\n");
    }
    return 0;
}
