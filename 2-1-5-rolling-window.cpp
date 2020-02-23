#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int max_q[N], min_q[N], a[N];

int max_hh = 0, max_tt = -1;
int min_hh = 0, min_tt = -1;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (min_hh <= min_tt && i - k + 1 > min_q[min_hh])
            min_hh++;
        while (min_hh <= min_tt && a[min_q[i]] >= a[i])
            min_hh--;
        min_q[++min_tt] = a[i];
        if (i - k + 1 >= 0)
            printf("%d", min_q[min_hh]);
    }
    for (int i = 0; i < n; i++)
    {
        if (max_hh <= max_tt && i - k + 1 > max_q[max_hh])
            max_hh++;

        while (max_hh <= max_tt && a[max_q[i]] <= a[i])
            max_tt--;
        min_q[++min_tt] = a[i];
        if (i - k + 1 >= 0)
            printf("%d ", max_q[max_hh]);
    }
}