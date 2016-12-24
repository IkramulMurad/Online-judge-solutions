#include <bits/stdc++.h>

using namespace std;

int n,m;

void printAnswer(int x, int y){
    if(x==n or y==m) printf("divisa\n");
    else if(x>n and y>m) printf("NE\n");
    else if(x<n and y<m) printf("SO\n");
    else if(x>n and y<m) printf("SE\n");
    else if(x<n and y>m) printf("NO\n");
}

int main()
{
    int q;
    while(cin>>q){
        if(!q) break;
        cin>>n>>m;

        int x,y;
        for(int i=0; i<q; ++i){
            cin>>x>>y;
            printAnswer(x,y);
        }
    }
    return 0;
}
