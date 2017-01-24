#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int zeroMn, oneMn;
    zeroMn=(m-1)/2;
    oneMn=n-1;

    if(n<zeroMn or m<oneMn){
        cout<<-1;
        return 0;
    }

    if(m==n){
        for(int i=0; i<m; ++i){
            cout<<"10";
        }
    }
    else if(m<n){
        cout<<"0";
        for(int i=0; i<m; ++i){
            cout<<"10";
        }
    }
    else if(m>n){
        while(m!=n){
            if(m>2){
                cout<<"11";
                m-=2;
            }
            else{
                cout<<"1";
                m-=1;
            }
            if(n){
                cout<<"0";
                --n;
            }

            if(m<=0) break;
        }
        while(m>0){
            cout<<"10";
            m-=1;
        }
    }
    return 0;
}
