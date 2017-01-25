#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin>>n;

    vector<pair<int, int> > v;
    for(int i=0; i<n; ++i){
        int a,b;
        cin>>a>>b;

        v.push_back(make_pair(a,b));
    }

    sort(v.begin(), v.end());

    int ans=v[0].second;
    for(int i=1; i<n; ++i){
        if(v[i].second<ans){
            ans=v[i].first;
        }
        else ans=v[i].second;
    }

    cout<<ans;

    return 0;
}
