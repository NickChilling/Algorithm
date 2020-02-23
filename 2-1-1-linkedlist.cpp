#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int allocater = 1;
int va[N];
int ne[N];
int head = 0; // 使用空节点

void add(int p, int v)
{
    va[allocater] = v;
    ne[allocater] = ne[p];
    ne[p] = allocater;
    allocater++;
}

void del(int k) // 删除第k个数相当于开挂？
{
    ne[k] = ne[ne[k]];
}

int main()
{
    ne[head] = -1;
    int m;
    cin >> m;
    char op;
    int x, k;
    while (m--)
    {
        cin >> op;

        if (op == 'H')
        {
            cin >> x;
            add(head, x);
        }
        else if (op == 'D')
        {
            cin >> k;
            del(k);
        }
        else
        {
            cin >> k >> x;
            add(k, x);
        }
    }
    int p = 0;
    while (ne[p] != -1)
    {
        p = ne[p];
        cout << va[p] << ' ';
    }
}