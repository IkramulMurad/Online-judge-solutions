#include <bits/stdc++.h>
 
using namespace std;
string intToString(long long a){
    string b;
    while(a){
        char c=(a%10)+48;
        b.push_back(c);
        a/=10;
    }
    reverse(b.begin(),b.end());
    return b;
}
long long stringToInt(string a){
    long long ans=0;
    int len=a.length();
    for(int i=0;i<len;i++){
        int x=a[i]-48;
        ans*=10;
        ans+=x;
    }
    return ans;
}
string getString(string s, long long b){
    long long ans=stringToInt(s);
    for(long long i=9;i>=0;i--){
        long long x=b*i;
        if(x<=ans){
            ans-=x;
            break;
        }
    }
    if(ans==0) return "";
    return intToString(ans);
}
int getAns(string a,long long b,int len){
    int flag=0;
    int len2=intToString(b).length();
    if(a[0]=='-'||a[0]=='+'){
        a.erase(0,1);
        len--;
    }
    while(len>len2||(len>=len2&&stringToInt(a)>=b)){
        string s;
        int i,chunk=len2,x=len-len2;
        for(i=0;i<chunk;i++){
            s.push_back(a[i]);
        }
        if(stringToInt(s)<b){
            chunk++;
            s.push_back(a[i]);
        }
        a.erase(0,chunk);
        s=getString(s,b);
        int slen=s.length();
        if(slen!=0) a.insert(0,s);
        len=len-chunk+slen;
        if(len<=0){
            flag=1;
            break;
        }
        if(a[0]=='0'){
            flag=1;
            break;
        }
    }
    return flag;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        char a[205];
        long long b;
        scanf("%s",a);
        scanf("%lld",&b);
        if(b<0) b*=-1;
        int len=strlen(a);
        if(b==1) printf("Case %d: divisible\n",i);
        else if(b==2){
            int x=a[len-1];
            if(x%2==0) printf("Case %d: divisible\n",i);
            else printf("Case %d: not divisible\n",i);
        }
        else if(len==1&&a[0]=='0')
            printf("Case %d: divisible\n",i);
        else if(len==2&&a[1]=='0')
            printf("Case %d: divisible\n",i);
        else{
            int flag=getAns(a,b,len);
            if(flag==1) printf("Case %d: divisible\n",i);
            else printf("Case %d: not divisible\n",i);
        }
    }
    return 0;
}
