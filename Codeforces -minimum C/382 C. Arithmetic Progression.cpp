#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    cin>>n;

    LL a[n];
    for(int i=0; i<n; ++i) cin>>a[i];

    //special case
    if(n==1){
        cout<<-1<<endl;
        return 0;
    }

    //process
    sort(a,a+n);

    set<LL> dif;
    for(int i=1; i<n; ++i){
        dif.insert(a[i]-a[i-1]);
    }

    if(dif.size()>2) cout<<0<<endl;
    else if(dif.size()==2){
        if(*dif.begin()*2!=*(++dif.begin())){
            cout<<0<<endl;
        }
        else{
            LL d=*dif.begin();
            LL ans=a[0],anz;

            //push n and one more value to multi set
            multiset<LL> res;
            res.insert(a[0]);

            bool flag=true;
            for(int i=1; i<n; ++i){
                ans+=d;
                if(a[i]!=ans and flag){
                    res.insert(ans);
                    anz=ans;
                    flag=false;
                }
                res.insert(a[i]);
            }

            //check consecutive multi set values have same difference
            bool no=false;
            LL prv=*res.begin();

            for(auto it=++res.begin(); it!=res.end(); ++it){
                if(*it!=prv+d){
                    no=true;
                    break;
                }
                prv=*it;
            }

            if(no) cout<<0<<endl;
            else{
                cout<<1<<endl;
                cout<<anz<<endl;
            }
        }
    }
    else{
        set<LL> ans;
        if(n==2 and !(*dif.begin()&1)){
            ans.insert(a[0]+*dif.begin()/2);
        }
        ans.insert(a[0]-*dif.begin());
        ans.insert(a[n-1]+*dif.begin());

        cout<<ans.size()<<endl;
        for(auto it=ans.begin(); it!=ans.end(); ++it){
            cout<<*it<<" ";
        }
        cout<<endl;
    }

    return 0;
}
