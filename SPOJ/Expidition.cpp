#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int tc;
    cin>>tc;
    while(tc--){
        LL n,l,p;
        cin>>n;
        vector<pair<LL,LL> > v;

        for(int i=0; i<n; ++i){
            LL x,y;
            cin>>x>>y;

            v.push_back(make_pair(x,y));
        }

        cin>>l>>p;


        for(int i=0; i<v.size(); ++i){
            v[i].first=l-v[i].first;
        }
        v.push_back(make_pair(l,0));
        sort(v.begin(),v.end());

        int kount, step, idx;
        kount = step = idx = 0;

        while(v[idx].first < 0) ++idx;

        int fuel = p;

        priority_queue<LL> pq;

        for(int i=idx; i<v.size(); ++i){
            if(fuel<v[i].first){
                while(!pq.empty() and fuel<v[i].first){
                    fuel += pq.top();
                    pq.pop();
                    ++kount;
                }
                if(fuel<v[i].first){
                    break;
                }
            }
            pq.push(v[i].second);
            ++step;
        }
        if(step<v.size()) cout<<-1<<endl;
        else cout<<kount<<endl;
    }
    return 0;
}
