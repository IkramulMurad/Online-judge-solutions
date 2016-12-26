#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; ++t){
        int n;
        cin>>n;

        int a[n];
        for(int i=0; i<n; ++i){
            string s;
            cin>>s;
            if(s[0]=='L') a[i]=-1;
            else if(s[0]=='R') a[i]=1;
            else{
                int x;
                string t;
                cin>>t>>x;
                --x;
                a[i]=a[x];
            }
        }
        int ans=accumulate(a,a+n,0);

        cout<<ans<<endl;
    }
    return 0;
}
