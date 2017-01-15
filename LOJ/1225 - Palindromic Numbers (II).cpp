#include <bits/stdc++.h>
 
using namespace std;
bool isPalindrome(string s){
    int len=s.length();
    int z=len/2;
    if(len%2)z++;
    for(int i=0,j=len-1;i<z;i++,j--){
        if(s[i]!=s[j])return 0;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        char n[12];
        scanf("%s",n);
        bool flag=isPalindrome(n);
        if(flag==0) printf("Case %d: No\n",i);
        else printf("Case %d: Yes\n",i);
    }
    return 0;
}
