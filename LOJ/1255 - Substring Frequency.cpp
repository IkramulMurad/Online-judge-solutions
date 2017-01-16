#include <bits/stdc++.h>
 
using namespace std;
 
const int n=1e6+5;
 
void makeFailureTable(int a[],string s,int len){
    int j=0;
    a[0]=0;
    for(int i=1;i<len;i++){
        if(s[i]==s[j]){
            j++;
            a[i]=j;
        }
        else{
            if(j==0) a[i]=0;
            else{
                j=a[j-1];
                i--;
            }
        }
    }
}
 
int KMPmatch(string t,string p,int a[],int lenP,int lenT){
    int j=0,kount=0;
    for(int i=0;i<lenT;i++){
        if(t[i]==p[j]){
            j++;
            if(j==lenP){
                j=a[j-1];
                kount++;
            }
        }
        else{
            if(j!=0){
                j=a[j-1];
                i--;
            }
        }
    }
    return kount;
}
 
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        char text[n],pattern[n];
 
        scanf("%s %s",text,pattern);
 
        int lenP=strlen(pattern), lenT=strlen(text);
        int a[lenP],kount=0;
 
        makeFailureTable(a,pattern,lenP);
        kount=KMPmatch(text,pattern,a,lenP,lenT);
 
        printf("Case %d: %d\n",i,kount);
    }
 
    return 0;
}
