#include <bits/stdc++.h>

using namespace std;

double eps=1e-5;
int p,q,r,s,t,u,flag;

double eqn(double x){
    return exp(-x)*p+sin(x)*q+cos(x)*r+tan(x)*s+x*x*t+u;
}

void binsearch(){
    double hi=1, lo=0, mid;
    while(hi>lo){
        mid=(hi+lo)/2;
        double val=eqn(mid);
        if(abs(val)<eps){
            flag=1;
            printf("%.4f\n",mid);
            return;
        }
        else if(val>0){
            lo=mid;
        }
        else hi=mid;
    }
}

void rbinsearch(){
    double hi=1, lo=0, mid;
    while(hi>lo){
        mid=(hi+lo)/2;
        double val=eqn(mid);
        if(abs(val)<eps){
            flag=1;
            printf("%.4f\n",mid);
            return;
        }
        else if(val>0){
            hi=mid;
        }
        else lo=mid;
    }
}

void solve(){
    //for bisection, f(a) and f(b) should be opposite sign
    if(eqn(0)*eqn(1)>0) printf("No solution\n");
    else{
        flag=0;
        binsearch();
        if(!flag) rbinsearch();
    }
}

int main()
{
    while(cin>>p>>q>>r>>s>>t>>u){
        solve();
    }
    return 0;
}
