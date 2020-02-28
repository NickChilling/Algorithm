## BFS , DFS

|DFS | stack | O(h) | 不是最短路径|
|BFS | queue | O(h^2)| 最短路径（边的权重始终为1时  |

```c++
#include <iostream>

using namespace std;

const int N =10;
int path[N];

void dfs(int u )
{
    if(u == n)
    {
        for (int i = 0; i < n ; i ++) printf("%d", path[i]);
        return;
    }
    for (int i = 1; i <= n ; i++)
    {
        if (!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u+1);
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}
``` 

### n 皇后问题
多开两个数组

## BFS
```c++
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 111;
int n, m;
int g[N][N];
int d[N][N];

PII q[N*N];

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = {0,0};
    memset(d,-1, sizeof(d));
    d[0][0] = 0;
    int dx[4] = {}
}
