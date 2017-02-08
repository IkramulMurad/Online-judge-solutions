#include <bits/stdc++.h>

using namespace std;

typedef pair<double,double> pd;
typedef pair<double,int> pdi;

const int mx=123;
vector<vector<int> > g(mx);
vector<vector<double> > c(mx);

double prims(){
    double ans=0;

    bitset<123> taken;

    priority_queue<pdi,vector<pdi>,greater<pdi>> pq;
    pq.push(make_pair(0,0));

    while(!pq.empty()){
        int node=pq.top().second;
        double cost=pq.top().first;

        pq.pop();

        if(!taken[node]){
            taken[node]=1;
            ans+=cost;
        }

        vector<int> v=g[node];
        vector<double> w=c[node];

        for(int i=0; i<v.size(); ++i){
            if(!taken[v[i]]){
                pq.push(make_pair(w[i],v[i]));
            }
        }
    }

    return ans;
}

int main()
{
    int tc,t=0;
    cin>>tc;

    while(tc--){
        //clear
        for(int i=0; i<mx; ++i) g[i].clear(), c[i].clear();

        //scan
        int n;
        cin>>n;

        pd a[n];
        for(int i=0; i<n; ++i){
            double x,y;
            cin>>x>>y;

            a[i]=make_pair(x,y);
        }

        //make graph
        for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                double x1=a[i].first;
                double y1=a[i].second;
                double x2=a[j].first;
                double y2=a[j].second;

                double cost=hypot(x2-x1,y2-y1);

                g[i].push_back(j);
                g[j].push_back(i);

                c[i].push_back(cost);
                c[j].push_back(cost);
            }
        }

        double ans=prims();

        if(t) cout<<endl;
        ++t;
        printf("%.2f\n",ans);
    }

    return 0;
}
