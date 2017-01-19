#include <bits/stdc++.h>

using namespace std;

void nlogn(int k, int n, int a[]){
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

void order_of_n(int k, int n, int a[]){
    deque<int> dq;

    //preparing deque
    for(int i=0; i<k; ++i){
        while(!dq.empty() and a[i]>=a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    //process
    for(int i=k; i<n; ++i){
        cout<<a[dq.front()]<<" ";

        while(!dq.empty() and dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() and a[i]>=a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<a[dq.front()]<<endl;
}

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

        //nlogn(k,n,a);

        order_of_n(k,n,a);
    }
    return 0;
}
