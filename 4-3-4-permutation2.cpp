#include <iostream>

using namespace std;

const int N = 100010, mod = 1e9 + 7;
typedef long long LL;
int fact[N], infact[N];

LL qmi(int a, int k, int q)
{
    LL res = 1;
    while (k)
    {
        if (k & 1)
            res = (LL)res * a % q;
        a = (LL)a * a % q;
        k >>= 1;
    }
    return res;
}
int main()
{
    infact[0] =1;
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        LL res = (LL) fact[a] * infact[b] % mod * infact[a-b] % mod;
        printf("%d\n", res);
    }
}