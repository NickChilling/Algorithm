#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int a[N];
int b[N];

int main()
{
    int n, m, l, r, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i] - a[i - 1];
    }
    while (m--)
    {
        scanf("%d %d %d", &l, &r, &c);
        b[l] = b[l] + c;
        b[r + 1] = b[r + 1] - c;
    }
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        tmp += b[i];
        printf("%d ", tmp);
    }
}