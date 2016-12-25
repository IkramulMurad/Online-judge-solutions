#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);

        printf("Case %d: ",t);
        if(x>20 or y>20 or z>20) cout<<"bad"<<endl;
        else cout<<"good"<<endl;
    }
    return 0;
}
