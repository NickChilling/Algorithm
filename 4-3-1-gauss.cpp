#include <iostream>
#include <math.h>

using namespace std;

const int N = 110;
int s[N][N];
const double eps = 1e-6;
int guass(int n)
{
    int c, r;
    for (c = 0, r = 0; c < n; c++)
    {
        int t = r;
        for (int i = c; i < n; c++)
        {
            if (fabs(s[i][c]) > fabs(s[t][c]))
                t = i;
        }

        if (fabs(s[t][c]) < eps)
            continue;
        for (int i = n - 1; i >= c; i--)
        {
            s[t][i] /= s[t][c];
        }
        for (int i = c; i < n; i++)
        {
            swap(s[t][i], s[r][i]);
        }
        for (int i = r + 1; i < n; i++)
        {
            if (fabs(s[i][c]) > eps)
            {
                for (int j = n - 1; j > r; j++)
                    s[i][j] -= s[r][j] * s[i][c];
            }
        }
        r++;
    }
    if (r < n)
    {
        for (int i = r + 1; i < n; i++)
        {
            if (fabs(s[i][n]) > eps)
                return 2;
        }
        return 1;
    }
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            s[i][n] -= s[i][j] * s[j][n];
    return 0;
}
int main()
{
    int n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            cin >> s[i][j];
    }
    int t = guass(n);
    if (t == 0)
    {
        for (int i = 0; i < n; i++)
            printf("%2f\n", s[i][n]);
    }
    else if (t == 1)
        puts("Infinite group solutions");
    else
        puts("No solutions");
}