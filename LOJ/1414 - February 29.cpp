#include <bits/stdc++.h>
 
using namespace std;
bool isLeap(int x){
    if(x%400==0) return true;
    if(x%100==0) return false;
    if(x%4==0) return true;
    return false;
}
int m2m(string s){
    if(s[0]=='D') return 12;
    if(s[0]=='N') return 11;
    if(s[0]=='O') return 10;
    if(s[0]=='S') return 9;
    if(s[0]=='F') return 2;
    if(s[0]=='A'&&s[1]=='u') return 8;
    if(s[0]=='A'&&s[1]=='p') return 4;
    if(s[0]=='M'&&s[2]=='r') return 3;
    if(s[0]=='M'&&s[2]=='y') return 5;
    if(s[0]=='J'&&s[1]=='a') return 1;
    if(s[0]=='J'&&s[2]=='n') return 6;
    if(s[0]=='J'&&s[2]=='l') return 7;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int date,date2,year,year2;
        char c;
        string month,month2;
        cin>>month>>date>>c>>year;
        cin.get();
        cin>>month2>>date2>>c>>year2;
        int m=m2m(month),m2=m2m(month2),ans=0;
        if(m>2)
        year++;
        if(m2<2||(m2==2&&date2<29))
        year2--;
        ans+=year2/4-(year-1)/4;
        ans-=year2/100-(year-1)/100;
        ans+=year2/400-(year-1)/400;
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
