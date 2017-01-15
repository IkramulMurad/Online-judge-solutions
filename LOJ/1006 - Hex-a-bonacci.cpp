#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, e, f,fnArray[10001];
int fn(int n)
{
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if(fnArray[n]!=0)
    {
        return fnArray[n];
    }
    else
    {
        fnArray[n]= fn(n - 1)% 10000007 + fn(n - 2)% 10000007 + fn(n - 3)% 10000007 + fn(n - 4)% 10000007 + fn(n - 5)% 10000007 + fn(n - 6)% 10000007;
        return fnArray[n];
    }
}
int main()
{
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    for(int i=1; i<=cases; i++)
    {
        memset(fnArray,0,sizeof(fnArray));
        cin>>a>>b>>c>>d>>e>>f>>n;
        printf("Case %d: %d\n",i, fn(n) % 10000007);
    }
    return 0;
}
