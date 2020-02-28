## 最小生成树
对应无向图。 一般不会用到有向图

1. prim 算法 （和 dijkstra 非常像） 
朴素版  O(n^2)  稠密图
堆优化 O(mlogn) 不常用
2. kruskal 算法(mlogm)  稀疏图

## 二分图
1. 如何判别二分图。 染色法 dfs  o(m+n)
2. 匈牙利算法  最坏 O(mn)  实际远小于


### 朴素prim
dist[i] = 无穷
n次迭代
找到集合外距离最近的点t。
用t更新其他点到集合的距离。
将t 加入到集合中


```c++
#include <cstring >
#include <iostream>
#include <algorithm>
using namspace std;

const int N = 510,INF = 0x3f3f3f3f;
int n,m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
    memset(dist,0x3f,sizeof dist);
    int res = 0 ; // 生成树中的边权之和
    for(int i = 0 ; i < n; i++)
    {
        int t = -1;
        for(int j =1; j <= n ; j++)
            if(!st[j] &&(t==-1 || dist[t]>dist[j])) t==j;
        if(i && dist[t]==INF) return INF;
        if(i) res += dist[t];
        for(int j = 1 ; j<= n ; j++) dist[j] = min(dist[j], g[t][j]); // 先更新再累加， 可能把自环加进来
        
        st[t] = true;
    }
    return res;
}

int main()
{
    cin >> n >> m;
    int t = prim();
    if (t==INF) puts("impossible");
    else printf("%d",t);

}
``` 

### kruskal
1. 将所有边按照从小到大排序 O(mlogm)
2. 枚举每条边 a->b 权重是c。如果a，b 不连通 就把这条边加到集合中
```c++
#include <iostream>
#include <cstring>
const int N = 10010;
int n,m;

int p[N];
struct Edge
{
    int a, b, w;
    bool operator< (const Edge &W) const
    {
        return w < W.w
    }
} edges[N];


int find(int a)
{
    if(p[a] != a) p[a] = find(a);
    return p[a]; 
}
int main()
{
    scanf("%d%d", &n , &m);
    for(int i =0 ; i < m ; i ++)
    {
        int a,b,w;
        scanf("%d%d%d", &a, &b,&w);
        edges[i] = {a,b,w};

    }
    sort(edges, edges+m);
    for(int i = 1; i <=n; i ++) p[i] = i;
    res = 0 , cnt = 0;  // res 生成树中权重之和。 cnt 当前加入多少条边
    for(int i = 1; i <= n ; i++)
    {
        int a = edges[i].a , b=edges[i].b, w= edges[i].w;

        a = find(a), b= find(b);
        if(a!=b)
        {
            p[a] = b;
            res += w;
            cnt ++;
        }
    }
    if(cnt < n -1 puts('impossible');
    else printf("%d\n",res);
    return 0 ;
}
```

### 二分图

一个图是二分图， 当且仅当图中不含奇数环
```c++
#include <iostream>

const int N = 100010, M =200020;

int h[N],e[M],ne[M], idx;
int color[N];

bool dfs(int u , int c)
{
    color[u] = c;
    for(int i = h[u]; i!=-1; i= ne[i])
    {
        int j = e[i];
        if(!color[j])
        {
            if(!dfs(j,3-c)) return false;
        }
        else if (color[j]==c) return false;
    }
    return true;

}


int main()
{
    for(int i=1 ; i<=n  ; i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1))
            {
                flag = false;
                break;
            }
        }
    }
    if(flag) puts("Yes");
    else put("No");
}
```
### 匈牙利算法

```c++
int match[N];
bool st[N];
bool find(int x)
{ 
    for(int i = h[x];i!=-1; i = ne[i])
    {
        int j = e[i];// 对应
        if(!st[j])
        {
            st[j] = true;
            if(match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
}
int main()
{
    int res = 0 ; 
    for(int i =1 ; i <=n1; i ++)
    {
        memset(st,false,sizeof st);
        if(find(i)) res ++;
    }
}