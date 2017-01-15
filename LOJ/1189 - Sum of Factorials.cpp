#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long fact[20];
    for(long long i=0;i<20;i++){
        if(i<=1) fact[i]=1;
        else fact[i]=i*fact[i-1];
    }
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        long long n;
        scanf("%lld",&n);
        int pos;
        for(int j=19;j>0;j--){
            if(n>=fact[j]){
                pos=j;
                break;
            }
        }
        vector<int> a;
        vector<int>::iterator it;
        for(int j=pos;j>=0;j--){
            if(n>=fact[j]){
                a.push_back(j);
                n-=fact[j];
            }
            if(n==0) break;
        }
        int len=a.size()-1;
        if(n!=0){
            printf("Case %d: impossible\n",i);
        }
 
        else{
            printf("Case %d: ",i);
            for(int j=len;j>0;j--){
                cout<<a[j]<<"!+";
            }
            cout<<a[0]<<"!"<<endl;
        }
    }
    return 0;
}
