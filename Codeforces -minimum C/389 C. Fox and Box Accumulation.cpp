#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    multiset<int> s;
    cin>>n;

    for(int i=0; i<n; ++i){
        int x;
        cin>>x;
        s.insert(x);
    }

    int ans=0;
    while(s.size()){
        int kount=0;
        auto it=s.begin();

        while(it!=s.end()){
            if(kount<=*it){
                s.erase(it++);
                ++kount;
            }
            else ++it;
        }
        ++ans;
    }

    cout<<ans;

    return 0;
}
