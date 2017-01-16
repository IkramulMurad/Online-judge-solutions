#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=1e7+5;
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
    int rng=mx/2;
    for(int i=3;i<=rng;i+=2){
        if(!bt[i]) v.push_back(i);
    }
}
 
int main()
{
    siv();
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int n;
        scanf("%d",&n);
 
        if(n==4){
            printf("Case %d: 1\n",t);
            continue;
        }
 
        int target=n/2;
        int ans=0;
        for(int i=0;i<v.size();++i){
            int x=v[i];
            if(x>target) break;
            if(!bt[n-v[i]]) ++ans;
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
