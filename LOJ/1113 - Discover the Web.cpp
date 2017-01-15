#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<":\n";
        stack<string> f,b;
        string current;
        current="http://www.lightoj.com/";
        while(true){
            string c;
            cin>>c;
            //cout<<b.size()<<" "<<f.size()<<endl;
            if(c[0]=='Q') break;
            else if(c[0]=='B'){
                if(b.empty()) cout<<"Ignored\n";
                else{
                    f.push(current);
                    current=b.top();
                    b.pop();
                    cout<<current<<endl;
                }
            }
            else if(c[0]=='F'){
                if(f.empty()) cout<<"Ignored\n";
                else{
                    b.push(current);
                    current=f.top();
                    f.pop();
                    cout<<current<<endl;
                }
            }
            else if(c[0]=='V'){
                string url;
                cin>>url;
                b.push(current);
                while(!f.empty()){
                    f.pop();
                }
                current=url;
                cout<<current<<endl;
            }
        }
    }
    return 0;
}
