#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[105], b[15];

void scan(){
    cin >> n >> s;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < s; ++i){
        cin >> b[i];
    }
}

void print(int t, bool alice){
    printf("Case %d: ", t);
    if(alice){
        printf("Alice\n");
    }
    else{
        printf("Bob\n");
    }
}

vector <int> getSet(){
    bool f[s];
    memset(f, 0, sizeof(f));
    sort(b, b + s);

    for(int i = 0; i < s; ++i){
        for(int j = i + 1; j < s; ++j){
            if(b[j] % b[i] == 0){
                f[j] = true;
            }
        }
    }

    vector <int> ans;
    for(int i = 0; i < s; ++i){
        if(f[i] == 0){
            ans.push_back(b[i]);
        }
    }
    return ans;
}

vector <int> getNumDivisor(int n, vector <int> &v){
    int sz = v.size();
    int rng = 1 << sz;
    vector <int> st(sz + 1, 0);

    for(int i = 1; i < rng; ++i){
        int x = __builtin_popcount(i);

        int total = 1;
        int k = i;
        for(int j = 0; k; ++j){
            if(k & 1){
                total *= v[j];
            }
            k >>= 1;
        }

        st[x] += n / total;
    }
    return st;
}

void prepareArray(vector <int> v){
    for(int i = 0; i < n; ++i){
        int x = 1;

        vector <int> numDivisors = getNumDivisor(a[i], v);
        //for(int k = 0; k < numDivisors.size(); ++k) cout << numDivisors[k] << " "; cout << endl;
        for(int j = 1; j < numDivisors.size(); ++j){
            if(j & 1) x += numDivisors[j];
            else x -= numDivisors[j];
        }

        a[i] = x;
    }
}

bool solve(){
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans ^= a[i];
    }
    return ans;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        scan();

        vector <int> v = getSet();
        //for(int i = 0; i < v.size(); ++i) cout << v[i] << " "; cout << endl;

        prepareArray(v);
        //for(int i = 0; i < n; ++i) cout << a[i] << " "; cout << endl;

        bool alice = solve();
        print(t, alice);
    }

    return 0;
}
