#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        long long m,x,X,Y,N;
        cin>>N;
        m=ceil(sqrt(N));
        x=m*m-m+1;
        //cout<<m<<" "<<x<<" "<<N<<endl;
        if(m%2==1)
        {
            if(N>x)
            {
                X=m-(N-x);
                Y=m;
            }
            else if(x>N)
            {
                X=m;
                Y=m-(x-N);
            }
            else
            {
                X=m;
                Y=m;
            }
        }
        else
        {
            if(N>x)
            {
                X=m;
                Y=m-(N-x);
            }
            else if(x>N)
            {
                X=m-(x-N);
                Y=m;
            }
            else
            {
                X=m;
                Y=m;
            }
        }
        cout<<"Case "<<i+1<<": "<<X<<" "<<Y<<endl;
    }
    return 0;
}
