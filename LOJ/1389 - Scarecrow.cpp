#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n;
        string s;
        scanf("%d",&n);
        getchar();
        cin>>s;
        int len=s.length();
        int kount=0;
        for(int i=len-1;i>=0;i--){
            if(s[i]=='.'){
                kount++;
                i-=2;
            }
        }
        printf("Case %d: %d\n",t,kount);
    }
    return 0;
}
