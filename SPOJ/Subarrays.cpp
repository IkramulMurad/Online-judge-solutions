#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    while(cin>>n){
        //scanning
        int a[n];
        for(int i=0; i<n; ++i){
            cin>>a[i];
        }
        cin>>k;

        //preparing set
        multiset<int> s;
        for(int i=0; i<k; ++i){
            s.insert(a[i]);
        }

        //process
        int hi,lo;
        hi=k-1;
        lo=0;
        for(int i=k-1; i<n; ++i){
            if(i!=k-1) cout<<" ";
            cout<<*s.rbegin();

            int x=a[++hi];
            s.insert(x);

            x=a[lo++];
            auto it=s.find(x);
            s.erase(it);
        }
        cout<<endl;
    }

    return 0;
}
