#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int q,c=1;
    while(cin>>s>>q){
        int a[s.size()];
        a[0]=s[0]-48;
        for(int i=1; i<s.size(); ++i){
            a[i]=a[i-1]+s[i]-48;
        }

        printf("Case %d:\n",c++);
        for(int i=0; i<q; ++i){
            int x,y,ans;
            cin>>x>>y;
            if(min(x,y)==0) ans=a[max(x,y)];
            else ans=a[max(x,y)]-a[min(x,y)-1];
            if(ans==0 or ans==max(x,y)-min(x,y)+1){
                printf("Yes\n");
            }
            else printf("No\n");
        }
    }
    return 0;
}
