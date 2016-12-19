#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
int dx[]={2,2,-2,-2,1,-1,1,-1};
int dy[]={1,-1,1,-1,2,2,-2,-2};

int main()
{
    int y1,y2;
    char x1,x2;
    while(cin>>x1>>y1>>x2>>y2){
        int x1_=x1-96,x2_=x2-96,lev=0;
        bool visited[8][8];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                visited[i][j]=false;
            }
        }
        queue< pi > position;
        map<pi ,int>level;
        position.push(make_pair(x1_,y1));
        visited[x1_-1][y1-1]=true;
        level[make_pair(x1_,y1)]=0;
        if(x1_==x2_ &&y1==y2){
            cout<<"To get from "<<x1<<y1 <<" to "<<x2<<y2 <<" takes "<<level[make_pair(x1_,y1)] <<" knight moves."<<endl;
            while(!position.empty()) position.pop();
        }
        while(!position.empty()){
            lev++;
            pi temp=position.front();
            int x=temp.first; int y=temp.second;
            position.pop();
            for(int i=0;i<8;i++){
                temp.first+=dx[i];
                temp.second+=dy[i];
                if(temp.first>=1 && temp.first<=8 && temp.second>=1 && temp.second<=8 && visited[temp.first-1][temp.second-1]==0){
                    position.push(make_pair(temp.first,temp.second));
                    visited[temp.first-1][temp.second-1]=true;
                    level[make_pair(temp.first,temp.second)]=level[make_pair(x,y)]+1;
                    //cout<<level[make_pair(temp.first,temp.second)];
                    if(temp.first==x2_ &&temp.second==y2){
                        cout<<"To get from "<<x1<<y1 <<" to "<<x2<<y2 <<" takes "<<level[make_pair(temp.first,temp.second)] <<" knight moves."<<endl;
                        while(!position.empty()) position.pop();
                        goto l1;
                    }
                }
                temp.first=x;temp.second=y;
            }
            l1:
            //something
            temp.first=x;temp.second=y;

        }
    }
    return 0;
}
