#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
LL h[N], q[N];
int p = 1331;

int cmp(int l , int r)
{
    return h[r] - h[l-1]*p[r-l+1];
}

int main()
{
    int n, m;
    char s[n];
    q[0] = 1;
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        h[i] = h[i-1]*p + s[i];
        q[i] = q[i-1]*p;
    }
    while(m--)
    {
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2 ;
        if (cmp(l1,r1) == cmp(l2,r2)) puts("Yes");
        else puts("No");
    }
}