#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    getchar();
    for(int i=1;i<=t;i++){
        string a,b;
        int n[26],m[26],flag=0;
        memset(n,0,sizeof(n));
        memset(m,0,sizeof(m));
        getline(cin,a);
        getline(cin,b);
        int lenA=a.length(), lenB=b.length();
        for(int j=0;j<lenA;j++){
            if((a[j]>='A'&&a[j]<='Z')||(a[j]>='a'&&a[j]<='z')){
                int index;
                if(a[j]>'Z') index=a[j]-97;
                else index=a[j]-65;
                n[index]+=1;
            }
        }
        for(int j=0;j<lenB;j++){
            if((b[j]>='A'&&b[j]<='Z')||(b[j]>='a'&&b[j]<='z')){
                int index;
                if(b[j]>'Z') index=b[j]-97;
                else index=b[j]-65;
                m[index]+=1;
            }
        }
        for(int j=0;j<26;j++){
            if(m[j]!=n[j]){
                flag=1;
                break;
            }
        }
        if(flag==0) printf("Case %d: Yes\n",i);
        else printf("Case %d: No\n",i);
    }
    return 0;
}
