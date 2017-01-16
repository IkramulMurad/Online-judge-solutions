#include <bits/stdc++.h>
 
using namespace std;
 
template<class T>
void fastIn(T& x){
    x=0;
    register int c;
    bool neg=false;
 
    c=getchar();
    if(c=='-'){
        neg=true;
        c=getchar();
    }
    while(c>47 and c<58){
        x=(x<<1)+(x<<3)+c-48;
        c=getchar();
    }
    if(neg){
        x*=-1;
    }
}
 
int main()
{
    int tc;
    fastIn<int>(tc);
    for(int t=1; t<=tc; ++t){
        long long n;
        fastIn<long long>(n);
 
        vector<long long> ans;
        long long x=n+n/9;
        if(!(n%9)){
            ans.push_back(x-1);
            ans.push_back(x);
        }
        else{
            ans.push_back(x);
        }
 
        printf("Case %d:",t);
        for(int i=0; i<ans.size(); ++i){
            printf(" %lld",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
