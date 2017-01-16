#include <bits/stdc++.h>
 
using namespace std;
 
const int rng=11;
int primes[rng]={2,3,5,7,11,13,17,19,23,29,31};
vector<vector<int> >fact(1001);
bitset<1005> prime,visited;
 
void siv(){
    prime[0]=prime[1]=1;
    for(int i=3; i<=31; i+=2){
        if(!prime[i]){
            for(int j=i*i; j<1001; j+=(i<<1)){
                prime[j]=1;
            }
        }
    }
}
 
void factorize(int a, vector<int>& v){
    int sq=sqrt(a);
 
    for(int i=0; i<rng and primes[i]<=sq; ++i){
        bool isDiv=false;
        while(a%primes[i]==0){
            a/=primes[i];
            isDiv=true;
        }
        if(isDiv){
            v.push_back(primes[i]);
        }
    }
    if(a!=1){
        v.push_back(a);
    }
}
 
void ok(){
    for(int i=2; i<=1000; ++i){
        factorize(i,fact[i]);
    }
}
 
int main()
{
    ok();
    siv();
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int a,b;
        scanf("%d %d",&a,&b);
 
        //special cases
       
        if(a==b){
            printf("Case %d: 0\n",t);
            continue;
        }
        if(a==1 or a==2 or a>b){
            printf("Case %d: -1\n",t);
            continue;
        }
        if(a&1 and !prime[a]){
            printf("Case %d: -1\n",t);
            continue;
        }
        //process
        visited.reset();
        vector<int> old,cur;
        old.push_back(a);
 
        bool found=0, neverFound=0;
        int ans=0;
        while(!found){
            ++ans;
            int sz=old.size();
            for(int i=0; i<sz; ++i){
                for(int j=0; j<fact[old[i]].size(); ++j){
                    int num=old[i]+fact[old[i]][j];
                    if(num==b){
                        found=1;
                        break;
                    }
                    else if(num<b and !visited[num]){
                        cur.push_back(num);
                        visited[num]=1;
                    }
                }
                if(found) break;
            }
            if(found) break;
            if(cur.size()==0){
                neverFound=1;
                break;
            }
 
            /*for(int k=0; k<cur.size(); ++k){
                cout<<cur[k]<<" ";
            }
            cout<<endl;*/
 
            old.clear();
            old=cur;
            cur.clear();
        }
 
        if(neverFound) printf("Case %d: -1\n",t);
        else if(found) printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
