#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5+10;

int h[N],ne[N],e[N],color[N];
int idx, n, m;
void add(int a, int b)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}
bool dfs(int node , int c)
{
    color[node] = c;
    for(int i = h[node]; i != -1; i = ne[i])
    {
        int ne_node = e[i];
        if(!color[ne_node])
        {
            if(!dfs(ne_node, 3-c)) return false;
        }
        else if (color[ne_node]==c) return false;
    }
    return true;
}
int main()
{
    cin >> n >>m;
    memset(h, -1, sizeof h);
    bool flag = true;
    while(m--)
    {
        int a, b, c;
        cin >> a >> b ;
        add(a,b),  add(b,a);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!color[i]) 
        {
            if(!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    }
    if (flag) puts("Yes");
    else puts("No");
}