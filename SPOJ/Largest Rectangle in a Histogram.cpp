// #define DBG_FILE
// #define DBG_FUN

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

typedef long long LL;

LL getAns(int a[], int n){
    stack <int> stk;
    LL mxArea = 0;
    int i = 0;

    while(i < n){
        if(stk.empty() or a[stk.top()] <= a[i]){
            stk.push(i++);
        }
        else{
            int x = stk.top(); stk.pop();
            if(stk.empty()){    //this item is smallest from 0 to i
                mxArea = max(mxArea, (LL)i * a[x]);
            }
            else{               //this item is smallest from stack top + 1 (previous small index + 1) to i - 1
                mxArea = max(mxArea, LL(i - stk.top() - 1) * a[x]);
            }
            #ifdef DBG_FUN
            cout << "i: " << i <<  ", x: " << x << ", a[x]: " << a[x] << endl;
            #endif
        }
    }

    #ifdef DBG_FUN
    cout << "After push n items" << endl;
    #endif

    while(!stk.empty()){
        int x = stk.top(); stk.pop();
        if(stk.empty()){    //this item is smallest from 0 to n
            mxArea = max(mxArea, (LL)n * a[x]);
        }
        else{               //this item is smallest from x(this) to n
            mxArea = max(mxArea, LL(n - stk.top() - 1) * a[x]);
        }
        #ifdef DBG_FUN
        cout << "x: " << x << ", a[x]: " << a[x] << endl;
        #endif
    }

    return mxArea;
}

int main(){
    #ifdef DBG_FILE
    freopen("in.txt", "r", stdin);
    #endif

    int n;
    while(cin >> n and n){
        int a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];

        cout << getAns(a, n) << endl;
    }

    return 0;
}
