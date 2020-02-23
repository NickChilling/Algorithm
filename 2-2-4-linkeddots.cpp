#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int se[N], cnt[N];

int find(int a)
{
    if (se[a] != a)
        se[a] = find(se[a]);
    return se[a];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        se[i] = i;
        cnt[i] = 1;
    }
    while (m--)
    {
        string op;
        int a, b;
        cin >> op;
        if (op == "C")
        {
            cin >> a >> b;
            int find_a = find(a);
            int find_b = find(b);
            if (find_a != find_b)
            {
                se[find_a] = find_b;
                cnt[find_b] += cnt[find_a];
            }
        }
        else if (op == "Q1")
        {
            cin >> a >> b;
            int find_a = find(a);
            int find_b = find(b);
            if (find_a != find_b) printf("No");
            else printf("Yes");
        }
        else
        {
            cin >> a ;
            printf("%d", cnt[find(a)]);
        }
    }
}