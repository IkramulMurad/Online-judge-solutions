#include <bits/stdc++.h>
 
using namespace std;
int getOnoroy(int n){
    int ans=0;
    while(n){
        if(n%2){
            ans++;
        }
    n/=2;
    }
    return ans;
}
vector<char> getBin(int n){
    vector<char> bin;
    while(n){
        if(n%2)bin.push_back('1');
        else bin.push_back('0');
        n/=2;
    }
    reverse(bin.begin(),bin.end());
    return bin;
}
vector<char> makeOnoroy(vector<char> bin){
    int posi=0,len=bin.size(),i,count0=0,count1=0;
 
    for(i=len-1;i>0;i--){
        if(bin[i]=='1') count1++;
    }
    for(i=len-1;i>0;i--){
        if(bin[i]=='1'){
            posi=i;
            break;
        }
    }
    for(i=posi;i>0;i--){
        if(bin[i]=='0') count0++;
    }
    if(count1==0){
        bin.insert(bin.begin()+1,'0');
    }
    else if(count0==0){
        int c=0,len=bin.size();
        bin.push_back('0');
        for(i=len;i>0;i--){
            if(bin[i]=='1'){
                c++;
            }
            bin[i]='0';
        }
        for(int j=1,i=len;j<=c;j++,i--){
            bin[i]='1';
        }
    }
    else{
        int c=0;
        for(i=posi;i>0;i--){
            if(bin[i]=='0'){
                bin[i]='1';
                break;
            }
            else {
                bin[i]='0';
                c++;
            }
        }
        for(int j=1,i=len-1;j<c;j++,i--){
            bin[i]='1';
        }
    }
    return bin;
}
int makeDecimal(vector<char> bin){
    int n=0,len=bin.size();
    for(int i=len-1,j=0;i>=0;i--,j++){
        int x=bin[i]-48;
        x=x*pow(2,j);
        n+=x;
    }
    return n;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("sol.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        long long n,m;
        vector<char> bin,ansbin;
        scanf("%lld",&n);
        m=n+1;
        int x=getOnoroy(n);
        
        bin=getBin(n);
        ansbin=makeOnoroy(bin);
        int ans=makeDecimal(ansbin);
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
