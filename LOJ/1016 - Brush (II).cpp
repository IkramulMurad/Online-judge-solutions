#include <bits/stdc++.h>
 
using namespace std;
 
class Point{
public:
    int x;
    int y;
};
 
bool operator<(Point a,Point b){
    if(a.y==b.y)
        return a.x<b.x;
    else return a.y<b.y;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n,w;
        scanf("%d %d",&n,&w);
        Point a[n];
        for(int i=0;i<n;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
        }
        sort(a,a+n);
        /*for(int i=0;i<n;i++){
            printf("%d %d\n",a[i].x,a[i].y);
        }*/
        int it=0,bound=0,kount=0;
        while(it<n){
            bound=w+a[it].y;
            kount++;
            while(a[it].y<=bound){
                it++;
                if(it>=n)break;
            }
        }
        printf("Case %d: %d\n",t,kount);
    }
    return 0;
}
