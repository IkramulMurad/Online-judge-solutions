#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m;
        cin>>n>>m;
        deque<int> a;
        cout<<"Case "<<i<<":\n";
        for(int j=0;j<m;j++){
            string s;
            cin>>s;
            if(s=="pushLeft"){
                int x;
                cin>>x;
                if(a.size()==n){
                    cout<<"The queue is full\n";
                }
                else{
                    a.push_front(x);
                    cout<<"Pushed in left: "<<x<<"\n";
                }
            }
            else if(s=="pushRight"){
                int x;
                cin>>x;
                if(a.size()==n){
                    cout<<"The queue is full\n";
                }
                else{
                    a.push_back(x);
                    cout<<"Pushed in right: "<<x<<"\n";
                }
            }
            else if(s=="popLeft"){
                if(a.size()==0){
                    cout<<"The queue is empty\n";
                }
                else{
                    int x=a.front();
                    a.pop_front();
                    cout<<"Popped from left: "<<x<<endl;
                }
            }
            else if(s=="popRight"){
                if(a.size()==0){
                    cout<<"The queue is empty\n";
                }
                else{
                    int x=a.back();
                    a.pop_back();
                    cout<<"Popped from right: "<<x<<endl;
                }
            }
        }
    }
    return 0;
}
