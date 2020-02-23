#include <iostream>
using namespace std;

const int N = 5e5 + 10;
int se[N], kind[N], cnt;

int find(int a)
{
    if (se[a] != a)
        se[a] = find(se[a]);
    return se[a];
}
// 需要+2

int relation(int a, int b)
{
    // -1 a 吃b  1 b吃a
    int a_loc = find(a + 2), b_loc = find(b + 2);
    if (a_loc > b_loc)
        return 1;
    else if (a_loc == b_loc)
        return 0;
    else
        return -1;
}
// 在每次说话的时候插入顺序， 关键在于如何初始化
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
        se[i] = i;
    while (k--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        // 一个指令进来  先验证信息， 再新增信息。
        //
        if (x > n || y > n)
        {
            cnt++;
            continue;
        }
        if (op == 2) // 不是同类时
        {
            if (x > n || y > n || x == y)
                cnt++;
        }
        else // 是同类时
        {
            int root_x = find(x), root_y = find(y);
            if (root_x == root_y)
                continue;
            else
            {
                bool flag = false;
                if (!kind[root_x])
                {
                    kind[root_x] = root_x;
                    flag = true;
                }
                if (!kind[root_x])
                {
                    kind[root_y] = root_x;
                    flag = true;
                }
                if (flag) continue;
                else
                {
                    
                }
            }
            {
            }
        }
    }
}