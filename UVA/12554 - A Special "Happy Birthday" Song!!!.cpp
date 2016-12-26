#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<string> person,song(16);
    for(int i=0; i<n; ++i){
        string s;
        cin>>s;
        person.push_back(s);
    }

    song[0]=song[4]=song[8]=song[12]="Happy";
    song[1]=song[5]=song[9]=song[13]="birthday";
    song[2]=song[6]=song[10]=song[14]="to";
    song[3]=song[7]=song[15]="you";
    song[11]="Rujia";

    int idx=0, jdx=0, done=0;

    while(!done){
        while(jdx<16){
            cout<<person[idx++]<<": "<<song[jdx++]<<endl;

            if(idx==n) done=1;

            idx%=n;
        }
        jdx%=16;
    }
    return 0;
}
