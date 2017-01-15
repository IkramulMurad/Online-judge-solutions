#include <bits/stdc++.h>
 
using namespace std;
struct Number{
    int num;
    int divisors;
    int rnk;
};
int getDivisorNumbers(int n){
    int rt=sqrt(n),ans=0;
    for(int i=1;i<=rt;i++){
        if(n%i==0){
            if(i==n/i) ans++;
            else ans+=2;
        }
    }
    return ans;
}
bool ranking(Number a,Number b){
    if(a.divisors==b.divisors)
        return a.num>b.num;
    else return a.divisors<b.divisors;
}
int main()
{
    int t;
    vector<Number> a(1001);
    a[0].divisors=0;
    for(int i=1;i<=1000;i++){
        a[i].num=i;
        a[i].divisors=getDivisorNumbers(i);
        //cout<<a[i].num<<" "<<a[i].divisors<<endl;
    }
    sort(a.begin(),a.end(),ranking);
 
    for(int i=0;i<=1000;i++){
        a[i].rnk=i;
    }
    /*for(int i=0;i<=100;i++){
        cout<<a[i].num<<" "<<a[i].rnk<<" "<<a[i].divisors<<endl;
    }*/
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",i,a[n].num);
    }
    return 0;
}
