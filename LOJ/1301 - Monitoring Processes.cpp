#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int n;
        scanf("%d",&n);
 
        vector<pair<int,bool> >v;
        for(int i=0; i<n; ++i){
            int x,y;
            scanf("%d %d",&x,&y);
            v.push_back(make_pair(x,0));
            v.push_back(make_pair(y,1));
        }
 
        sort(v.begin(),v.end());
 
        int ans=0,kount=0;
        for(int i=0; i<n+n; ++i){
            if(v[i].second){
                --kount;
            }
            else{
                ++kount;
            }
            ans=max(ans,kount);
        }
 
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
