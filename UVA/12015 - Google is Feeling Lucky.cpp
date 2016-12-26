#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; ++t){
        vector<pair<int, pair<int,string> > >v;
        int x;
        string s;

        for(int i=0; i<10; ++i){
            cin>>s>>x;
            v.push_back(make_pair(x,make_pair(10-i,s)));
        }

        sort(v.begin(), v.end());

        int val=v.back().first;

        printf("Case #%d:\n",t);
        while(val==v.back().first and !v.empty()){
            cout<<v.back().second.second<<endl;
            v.pop_back();
        }
    }
    return 0;
}
