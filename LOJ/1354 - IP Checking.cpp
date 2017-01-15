#include <bits/stdc++.h>
 
using namespace std;
int w,x,y,z;
int makeDec(string n){
    int ans=0;
    //cout<<n<<endl;
    for(int i=7,j=0;i>=0;i--,j++){
        int x=n[i]-48;
        ans+=(x)*pow(2,j);
    }
    return ans;
}
void convertToDecimal(string s){
    char n[9];
    int j,i;
    for(j=0;j<8;j++){
        n[j]=s[j];
    }
    n[j]='\0';
    w=makeDec(n);
    for(i=0,j=9;j<17;j++,i++){
        n[i]=s[j];
    }
    n[i]='\0';
    x=makeDec(n);
    for(int i=0,j=18;j<26;j++,i++){
        n[i]=s[j];
    }
    n[i]='\0';
    y=makeDec(n);
    for(int i=0,j=27;j<35;j++,i++){
        n[i]=s[j];
    }
    n[i]='\0';
    z=makeDec(n);
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int a,b,c,d;
        char ch;
        string s;
        cin>>a>>ch>>b>>ch>>c>>ch>>d;
        cin>>s;
        convertToDecimal(s);
        if(a==w&&b==x&&c==y&&d==z){
            cout<<"Case "<<i<<": Yes\n";
        }
        else cout<<"Case "<<i<<": No\n";
    }
    return 0;
}
