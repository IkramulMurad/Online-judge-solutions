#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int a[n][n];
    int first=1, second=(k-1)*n+1;
    //set value
    for(int i=0; i<n; ++i){
        for(int j=0; j<k-1; ++j){
            a[i][j]=first++;
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=k-1; j<n; ++j){
            a[i][j]=second++;
        }
    }

    //calculate sum
    int sum=0;
    for(int i=0; i<n; ++i){
        sum+=a[i][k-1];
    }

    cout<<sum<<endl;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
