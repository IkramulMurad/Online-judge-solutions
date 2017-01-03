#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int a[100];

    int tc,c=1;
    cin>>tc;
    while(tc--){
        for(int i=0; i<100; ++i) a[i]=0;
        string s;
        cin>>s;
        int p=0;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='+'){
                a[p]=((a[p]+1)%256);
            }
            else if(s[i]=='-'){
                a[p]=((a[p]-1+256)%256);
            }
            else if(s[i]=='>'){
                p=(p+1)%100;
            }
            else if(s[i]=='<'){
                p=(p-1+100)%100;
            }
        }
        printf("Case %d:",c++);
        for(int i=0; i<100; ++i){
            printf(" %02X",a[i]);
        }
        printf("\n");
    }
    return 0;
}
