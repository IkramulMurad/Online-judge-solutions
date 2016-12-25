#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        string s;
        cin>>s;
        int len=s.size();

        if(s[len-2]=='3' and s[len-1]=='5'){
            cout<<"-"<<endl;
        }
        else if(s[0]=='9' and s[len-1]=='4'){
            cout<<"*"<<endl;
        }
        else if(s[0]=='1' and s[1]=='9' and s[2]=='0'){
            cout<<"?"<<endl;
        }
        else{
            cout<<"+"<<endl;
        }
    }
    return 0;
}
