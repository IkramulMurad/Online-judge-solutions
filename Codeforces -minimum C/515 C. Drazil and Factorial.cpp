#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s,ans;
    cin>>n>>s;

    for(int i=0; i<n; ++i){
        if(s[i]=='0' or s[i]=='1') continue;
        else if(s[i]=='4'){
            ans+="322"; //f(4)=f(3)*f(2)*f(2)
        }
        else if(s[i]=='6'){
            ans+="53"; //f(6)=f(5)*f(3)
        }
        else if(s[i]=='8'){
            ans+="7222"; //f(8)=f(7)*f(2)*f(2)*f(2)
        }
        else if(s[i]=='9'){
            ans+="7332"; //f(9)=f(7)*f(3)*f(3)*f(2)
        }
        else{
            ans.push_back(s[i]);
        }
    }

    sort(ans.begin(), ans.end());
    reverse(ans.begin(),ans.end());

    cout<<ans;

    return 0;
}
