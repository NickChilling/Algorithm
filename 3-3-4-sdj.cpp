#include <iostream>
#include <cstring>

using  namespace std; 

// 这道题虽然m = 1e5 但还是用邻接表比较方便。 如果要用邻接矩阵 需要区分n1,n2;
const int N = 510;

int h[N], ne[N], e[N], match[N],st[N];

int idx;

void add(int a , int b)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

bool find(int node)
{
    for(int i = h[node]; i != -1; i = ne[i])
    {
        int ne_node = e[i];
        if(!st[ne_node])
        {
            st[ne_node] = 1;
            if(match[ne_node]==0 || find(match[ne_node]))
            {
                match[ne_node] = node;
                return true;
            }
        }

    }
    return false;
}
int main()
{
    int n1,n2,m;
    memset(h, -1, sizeof h);
    cin >> n1 >> n2>> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        add(a,b);
    }
    int res = 0;
    for(int i = 1 ; i <= n1; i++)
    {
        memset(st, false, sizeof st);
        if(find(i)) res++;
    }
}