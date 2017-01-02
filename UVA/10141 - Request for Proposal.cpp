#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int n,p,c=0;
    while(cin>>n>>p and n and p){
        getchar();
        string s;
        for(int i=0; i<n; ++i) {
            getline(cin,s);
        }

        string prop,ansProp;
        int num,ansNum=0;
        double price,ansPrice=0;

        for(int i=0; i<p; ++i){
            getline(cin,prop);
            cin>>price>>num;
            getchar();
            string x;
            for(int j=0; j<num; ++j) getline(cin,x);
            if(num>ansNum){
                ansNum=num;
                ansProp=prop;
                ansPrice=price;
            }
            else if(num==ansNum){
                if(price<ansPrice){
                    ansNum=num;
                    ansProp=prop;
                    ansPrice=price;
                }
            }
        }
        if(c) printf("\n");
        printf("RFP #%d\n",++c);
        cout<<ansProp<<endl;
    }
    return 0;
}
