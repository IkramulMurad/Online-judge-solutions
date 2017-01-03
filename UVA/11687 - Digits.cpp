#include <bits/stdc++.h>

using namespace std;

int count(int x){
    int ans=0;
    while(x>0){
        ++ans;
        x/=10;
    }
    return ans;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    string s;
    while(cin>>s){
        if(s=="END") break;
        if(s=="1"){
            cout<<1<<endl;
            continue;
        }
        int x=s.size();
        int kount=1;
        while(x!=count(x)){
            x=count(x);
            ++kount;
        }
        cout<<kount+1<<endl;
    }
    return 0;
}
