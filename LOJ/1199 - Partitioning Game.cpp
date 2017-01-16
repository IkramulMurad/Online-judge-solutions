#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=1e4+5;
int g[mx];
 
void calculate_grundy(){
    g[0]=g[1]=g[2]=0;
    for(int i=3;i<10001;++i){
        set<int> s;
        set<int>::iterator it;
        for(int j=(i>>1)+1; j<i; ++j){
            s.insert(g[j]^g[i-j]);
        }
        int k=0;
        for(it=s.begin(); it!=s.end(); ++it){
            if(k!=*it) break;
            ++k;
        }
        g[i]=k;
    }
}
 
int main()
{
    calculate_grundy();
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int n;
        scanf("%d",&n);
        long long ans=0;
        int a[n];
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            ans^=g[a[i]];
        }
        if(ans) printf("Case %d: Alice\n",t);
        else printf("Case %d: Bob\n",t);
    }
    return 0;
}
