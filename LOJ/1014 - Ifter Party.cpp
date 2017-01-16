#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int p,l;
        scanf("%d %d",&p,&l);
        int n=p-l;
        int sq=sqrt(n);
        vector<int> v;
        for(int i=1;i<=sq;++i){
            if(n%i==0){
                v.push_back(i);
                if(i!=n/i)v.push_back(n/i);
            }
        }
        sort(v.begin(),v.end());
        int flag=0;
        printf("Case %d:",t);
        for(int i=0;i<v.size();++i){
            if(v[i]>l){
                flag=1;
                printf(" %d",v[i]);
            }
        }
        if(!flag) printf(" impossible");
        printf("\n");
    }
    return 0;
}
