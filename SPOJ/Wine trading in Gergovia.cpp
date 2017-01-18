#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;
    while(cin>>n and n){
        int a[n];
        for(int i=0; i<n; ++i){
            cin>>a[i];
        }

        vector<pair<int,int> > pos, neg;
        for(int i=0; i<n; ++i){
            if(a[i]<0){
                neg.push_back(make_pair(a[i],i+1));
            }
            else if(a[i]>0){
                pos.push_back(make_pair(a[i],i+1));
            }
        }

        /*for(int i=0; i<pos.size(); ++i) cout<<pos[i].first<<" ";
        cout<<endl;
        for(int i=0; i<neg.size(); ++i) cout<<neg[i].first<<" ";
        cout<<endl;
        */

        LL ans=0;
        int idx=0;
        for(int i=0; i<pos.size(); ++i){
            LL step=0;
            while(pos[i].first){
                int mn=min(pos[i].first,abs(neg[idx].first));
                step+=(LL)abs(pos[i].second-neg[idx].second)*mn;

                pos[i].first-=mn;
                neg[idx].first+=mn;

                if(!neg[idx].first) ++idx;
            }
            ans+=step;
        }

        cout<<ans<<endl;
    }
    return 0;
}
