#include <bits/stdc++.h>

using namespace std;

const int mx=1e5+5;

int n,m;
int a[mx],b[mx];

bool getIndex(int &i, int &j){
    if(i>n or j>m) return false;
    while(i<=n and j<=m){
        if(a[i]==b[j]){
            return true;
        }
        while(a[i]>b[j]){
            ++j;
        }
        while(a[i]<b[j]){
            ++i;
        }
    }
}

void sumProcess(int &mx1, int &mx2, int p1, int p2, int x, int y){
    for(int i=p1; i<=x; ++i){
        mx1+=a[i];
    }
    for(int i=p2; i<=y; ++i){
        mx2+=b[i];
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>n and n){
        int last;
        for(int i=0; i<n; ++i) cin>>a[i],last=i;
        a[last+1]=mx;

        cin>>m;
        for(int i=0; i<m; ++i) cin>>b[i],last=i;
        b[last+1]=mx;

        int mx1,mx2,ans;
        mx1=mx2=ans=0;

        int pp1,pp2,i,j;
        pp1=pp2=i=j=0;

        while(getIndex(i,j)){
            sumProcess(mx1,mx2,pp1,pp2,i,j);
            ans+=max(mx1,mx2);

            mx1=mx2=0;
            ++i;
            ++j;
            pp1=i;
            pp2=j;
        }

        ans-=mx;
        cout<<ans<<endl;
    }
    return 0;
}
