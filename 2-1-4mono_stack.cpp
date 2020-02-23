#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N], s[N];
int tt = -1;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
        if (tt < 0)
        {
            printf("-1");
            s[++tt] = q[i];
        }
        else
        {
            while(s[tt] >= q[i]) tt--;
            if (tt < 0) printf("-1 ");
            else
                printf("%d",s[tt]);
            s[++tt] = q[i];
        }
    }

}