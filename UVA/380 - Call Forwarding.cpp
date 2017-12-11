#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

const int mx = 100 + 5;
int n;
int a[mx][9999];
int index[mx], it;

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void init(){
    it = 0;
    for(int i = 0; i < mx; ++i){
        index[i] = -1;
        for(int j = 0; j < 9999; ++j){
            a[i][j] = 0;
        }
    }
}

void push(int source){
    index[it] = source;
    ++it;
}

int indexOf(int source){
    int idx = -1;
    for(int i = 0; i < mx; ++i){
        if(index[i] == source){
            idx = i;
        }
    }
    return idx;
}

void makeTimeTable(int source, int timestamp, int duration, int target){
    if(indexOf(source) == -1) push(source);
    for(int i = 0; i <= duration; ++i){
        a[indexOf(source)][timestamp + i] = target;
    }
}

void scan(){
    int source, timestamp, duration, target;
    while(cin >> source and source){
        cin >> timestamp >> duration >> target;
        makeTimeTable(source, timestamp, duration, target);
    }
}

void print(int timestamp, int source, int ans){
    cout << "AT " << setw(4) << setfill('0') << timestamp;
    cout << " CALL TO " << setw(4) << setfill('0') << source;
    cout << " RINGS " << setw(4) << setfill('0') << ans << endl;
}

int solve(int code, int timeStamp, int orgCode){
//    cerr << code << "-> " << indexOf(code) << ": ";
//    cerr << "a[" << indexOf(code) << "][" << timeStamp << "] = " << a[indexOf(code)][timeStamp] << endl;
    if(indexOf(code) == -1) return code;
    if(a[indexOf(code)][timeStamp] == 0) return code;
    if(a[indexOf(code)][timeStamp] == orgCode) return 9999;

    solve(a[indexOf(code)][timeStamp], timeStamp, orgCode);
}

void solveSystem(int i){
    int source, timestamp;
    while(cin >> timestamp){
        if(timestamp == 9000) break;
        cin >> source;
        print(timestamp, source, solve(source, timestamp, source));
    }
}

int main()
{
    //fileInput();

    cout << "CALL FORWARDING OUTPUT" << endl;
    cin >> n;
    for(int i = 0; i < n; ++i){
        init();
        scan();
        cout << "SYSTEM " << i + 1 << endl;
        solveSystem(i);
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
