#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        int n;
        char a[10];
        scanf("%d",&n);
        getchar();
        scanf("%s",a);
        if(a[0]=='A'){
            if(n%3==1){
                printf("Case %d: Bob\n",t);
            }
            else{
                printf("Case %d: Alice\n",t);
            }
        }
        else if(a[0]=='B'){
            if(n%3==0){
                printf("Case %d: Alice\n",t);
            }
            else{
                printf("Case %d: Bob\n",t);
            }
        }
    }
    return 0;
}
