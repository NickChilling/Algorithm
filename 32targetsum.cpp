#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    int l,r;
    for (int i = 0; i < n; i++)
    {
        int j = m - 1;
        while (a[i] + b[j] >x && j >= 0) j--;
            if (a[i] + b[j] == x)
            {
                printf("%d %d\n", i,j );
                break;
            }
        
    }

}