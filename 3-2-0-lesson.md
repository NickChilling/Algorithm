# 最短路

常见的最短路问题有两种。
1. 单源最短路： 一个点到其他所有点的最短距离。
    可进一步细分
    1.1 所有边权都是正数    朴素Dijkstra  $O(n^2)$  稠密图
     堆优化 Dijkstra   $O(mlogn)$ 稀疏图  稠密时  m = n^2 
    1.2 存在负权边   Bellman-ford O(nm)
                     SPFA  O(m) 一般情况下 最坏 nm
2. 多源汇最短路。 起点和终点不确定。Floyd  o(n^3)

## dijkstra
```c++
#include <iostream>
#include <cstring>
#include <algorithm>

// 用邻接矩阵

using namespace std ;
const int N =510;
// 存在自环和重边
// 只保留距离最短的那条边。
int g[N][N]; 
int dist[N];
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < n ; i ++)
    {
        int t = -1;
        for(int j = 1; j <=n ; j++)
        {
            if (!st[j] &&(t==-1|| dist[t]>dist[j])) t= j; // 用堆优化这里
        }
        st[t] = true;
        for(int j = 1 ; j<= n ; j++) dist[j] = min(dist[j],dist[t]+g[t][j])
    }
    if (dist[n] == 0x3f3f3f) return -1;
    else return dist[n];
}
int main()
{
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while (m--)
    {
        int a,b,c;
        cin >> a>> b>>c;
        g[a][b] = min(g[a][b],c);
    }
}

// 堆优化
// 稀疏图 用邻接表的形式
#include <queue>
typedef pair<int,int> PII;
int n,m;
int h[N],w[N], e[N], ne[N];
int dist[N];
bool st[N];
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] =0;
    priority_queue<PII, vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        for(int i = h[t]; i!=-1;i=ne[i])
        {
            int j = e[i];
            if(dist[j] > distance+ w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j],j});
            }
        }
    }

}
```
Bellman-ford  
for n 次  迭代k次， 最多不经过k条边
备份 -> 保证只使用上一次迭代的结果。 保留限制
如果不备份， 可能会有串联， 导致使用到这一轮更新的结果
 for 所有边 a,b,w 
     dist[b] = min(dist[b],dist[a]+w)

如果存在负权回路， 那么可能不存在最短路径

```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namspace std;

const int N = 510, M = 10010;
int n, m; 
int dist[N], backup[N];
struct Edge
{
    int a,b,w;
}edges[M];

int bellman_ford()
{
    for(int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);
        for(int j = 0 ; j <m; j++)
        {
            int a = edges[j].a, b= edges[j].b, w=edges[j].w;
            dist[b] = min(dist[b],backup[a]+w);
        }
    }
    if(dist[n] > 0x3f3f3f3f/2) return -1;// 负权边可能会更新到不了的点。
    return dist[n];
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0 ; i < m ; i++)
    {
        int a,b,w;
        scanf("%d%d%d", &a, &b,&w);
        edges[i] = (a,b,w);
    }
    int t = bellman_ford();
    if(t==-1) puts("impossible");
    else printf("%d\n", t);
}
```

```c++
int spfa()
{
    memset(dist ,0x3f, sizeof dist);
    dist[1]= 0;
    queue<int> q;
    q.push(1);
    st[1] = true;

    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t] ; i != -1 ; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] +w[i])
            {
                dist[j] = dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]= true;  // 避免多次入队
                }
            }
        }
    }
}
``` 
判断负环。 如果每次更新最短路径时，cnt[t] = cnt[a]+1; 如果某个cnt 大于n 那么存在 负环
一开始需要把所有点入队， 因为可能从1到不了负环


## floyd 
for()

d[k,i,j] 只经过1-k 从i到j的最短距离
d[k,i,j] = d[k-1,i,k] + d[k-1,k,j]

```c++
void floyd()
{
    for(int k = 1 ; k<= n ;k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j =1 ; j<= n ; j++)
            {
                d[i][j] = min(d[i][j],d[i][k]+d[k][j])
            }
        }
    }
}