#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x,y,z;

    Point(int a, int b, int c){
        x=a; y=b; z=c;
    }
};

vector<Point> points;
vector<double> dist;
const double inf=2e9+5.0;

double distance(int x, int y, int z){
    int ans=x*x+y*y+z*z;
    return sqrt(ans);
}

double calculate(int i, int j){
    int ax=points[i].x;
    int bx=points[j].x;

    int ay=points[i].y;
    int by=points[j].y;

    int az=points[i].z;
    int bz=points[j].z;

    return (distance(ax-bx,ay-by,az-bz));
}

int kount(double a, double b){
    int ans=0;
    for(int i=0; i<dist.size(); ++i){
        if(dist[i]>=a and dist[i]<b){
            ++ans;
        }
    }
    return ans;
}

int main()
{
    int x,y,z;
    while(cin>>x>>y>>z and (x or y or z)){
        points.push_back(Point(x,y,z));
    }

    for(int i=0; i<points.size(); ++i){
        double d=inf;
        for(int j=0; j<points.size(); ++j){
            if(i!=j){
                d=min(d,calculate(i,j));
            }
        }
        dist.push_back(d);
    }

    sort(dist.begin(),dist.end());

    for(int i=0; i<dist.size(); ++i){
        cerr<<dist[i]<<endl;
    }

    for(int i=0; i<10; ++i){
        double range=i+1;
        printf("%4d",kount(i,range));
    }

    cout<<endl;

    return 0;
}
