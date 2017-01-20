
#include <bits/stdc++.h>

using namespace std;

string processMax(int n, int m){
    string mx(n,'0');
    cerr<<mx<<endl;

    for(int i=0; i<n; ++i){
        if(m>=9) mx[i]='9';
        else mx[i]=char('0'+m);
        m-=9;
        if(m<=0) break;
    }

    return mx;
}

string processMin(int n, int m){
    string mn(n,'0');

    mn[0]='1';
    m-=1;

    for(int i=n-1; i>0; --i){
        if(m>=9) mn[i]='9';
        else mn[i]=char('0'+m);
        m-=9;
        if(m<=0) break;
    }
    if(m>0) mn[0]=char(mn[0]+m);

    return mn;
}

int main()
{
    int n,m;
    cin>>n>>m;

    //special case
    if(n==1 and !m){
        cout<<0<<" "<<0<<endl;
        return 0;
    }

    if(n*9<m or !m){
        cout<<-1<<" "<<-1<<endl;
    }
    else{
        string mx,mn;
        mx=processMax(n,m);
        mn=processMin(n,m);
        cout<<mn<<" "<<mx<<endl;
    }
    return 0;
}
