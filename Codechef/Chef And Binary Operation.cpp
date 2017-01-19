#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=1e6+5;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        string a,b;
        cin>>a>>b;
        bitset<mx> bits(a);
        int len=a.length();
        int total=0,oneToZero=0,zeroToOne=0;
        if(bits.count()==len||bits.count()==0){
            printf("Unlucky Chef\n");
        }
        else{
            for(int i=0;i<len;i++){
                if(a[i]!=b[i]){
                    total++;
                    if(a[i]=='1')oneToZero++;
                    else zeroToOne++;
                }
            }
            total-=min(oneToZero,zeroToOne);
            printf("Lucky Chef\n%d\n",total);
        }
    }
    return 0;
} 
