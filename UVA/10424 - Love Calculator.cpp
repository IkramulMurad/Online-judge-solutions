#include <bits/stdc++.h>

using namespace std;

int getSum(string s){
    int ans=0;
    for(int i=0; i<s.size(); ++i){
        if(s[i]>='A' and s[i]<='Z') ans+=s[i]-'A'+1;
        else if(s[i]>='a' and s[i]<='z') ans+=s[i]-'a'+1;
    }
    return ans;
}

int digit(int x){
    int ans=0;
    while(x>0){
        ans+=x%10;
        x/=10;
    }
    return ans;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    string s,t;
    while(getline(cin,s)){
        getline(cin,t);

        int a=getSum(s);
        int b=getSum(t);

        while(a>9) a=digit(a);
        while(b>9) b=digit(b);

        double ans=double(min(a,b))/double(max(a,b));
        ans*=100;
        printf("%.2f %\n",ans);

    }
    return 0;
}
