#include <bits/stdc++.h>
using namespace std;

multiset <int> input(int n){
    multiset <int> ms;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;

        ms.insert(x);
    }

    return ms;
}

bool process(string s){
    stack <char> st;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '('){
            st.push(s[i]);
        }
        else if(!st.empty()){
            st.pop();
        }
        else{
            return true;
        }
    }

    return !st.empty();
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int n;
        cin >> n;

        multiset <int> ms = input(n);

        cout << "Case " << t << ": ";

        string s = "";
        int last = 0;
        bool invalid = false;
        for(int i = 0; i < n; ++i){
            auto it = ms.find(last + 1);
            if(it != ms.end()){
                s += "(";
                last++;
                ms.erase(it);
                continue;
            }

            it = ms.find(last - 1);
            if(it != ms.end()){
                s += ")";
                last--;
                ms.erase(it);
            }
            else{
                invalid = true;
                break;
            }
        }

        //cout << s << endl;

        if(invalid){
            cout << "invalid" << endl;
        }
        else{
            invalid = process(s);
            if(invalid) cout << "invalid" << endl;
            else cout << s << endl;
        }
    }

    return 0;
}
