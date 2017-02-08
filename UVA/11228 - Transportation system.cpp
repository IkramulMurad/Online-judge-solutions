#include <bits/stdc++.h>

using namespace std;

typedef pair<double,int> pd;

const int mx=1005;
int n;
vector<vector<int> > g(mx);
vector<vector<double> > c(mx);
double th;
double eps=0.0001;

void prims(){
    int state=1,total=0;
    double ans1,ans2;
    ans1=ans2=0;

    bitset<mx> taken;

    priority_queue<pd,vector<pd>,greater<pd>> pq;
    pq.push(make_pair(0,0));

    while(!pq.empty()){
        int node=pq.top().second;
        double cost=pq.top().first;

        pq.pop();

        if(!taken[node]){
            taken[node]=1;

            if(abs(cost-th)<eps){
                ans1+=cost;
            }
            else if(cost<th){
                ans1+=cost;
            }
            else if(cost>th){
                ans2+=cost;
                ++state;
            }

            ++total;
            if(total==n) break; //this saved me from tle
        }

        vector<int> v=g[node];
        vector<double> w=c[node];

        for(int i=0; i<v.size(); ++i){
            if(!taken[v[i]]){
                pq.push(make_pair(w[i],v[i]));
            }
        }
    }

    int res1=round(ans1);
    int res2=round(ans2);

    printf("%d %d %d\n",state,res1,res2);
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; ++t){
        //scan
        scanf("%d %lf",&n,&th);

        int x[n],y[n];

        for(int i=0; i<n; ++i){
            scanf("%d %d",x+i,y+i);
        }

        //clear
        for(int i=0; i<n; ++i) g[i].clear(), c[i].clear();

        //make graph
        for(int i=0; i<n-1; ++i){
            for(int j=0; j<n; ++j){
                double cost=hypot(x[j]-x[i],y[j]-y[i]);

                g[i].push_back(j);
                g[j].push_back(i);

                c[i].push_back(cost);
                c[j].push_back(cost);
            }
        }
        printf("Case #%d: ",t);
        prims();

    }

    return 0;
}
