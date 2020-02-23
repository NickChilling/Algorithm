## trie 树

作用： 用来快速存储、查找字符串集合的数据结构

```c++
#include <iostream>

using namespace std;
const int N = 100010;

int son[N][26],cnt[N],idx; // 下标是0 的点，既是根节点又是空节点。


void insert(char str[])
{
    int p = 0;
    for(int i = 0 ; str[i];i++ )
    {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
}
int query(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u]
    }
    return cnt[p];
}
int main()
{
    int n ; 
    scanf("%d", &n);
    while(n--)
    {
        char op[2];
        scanf("%s%s",op, str);
        if(op[0] == 'I') insert(str);
        else printf("%d\n", query(str));
    }
    return 0;
}
```
## 并查集

1. 将两个集合合并
2. 询问两个元素是否在一个集合中

用数组来保存x是否属于某个集合 
beglong[x] == belong[y] 
这样将两个集合合并时，需要遍历集合中的元素
并查集可以用o(1)
基本原理： 用树维护集合。 每个集合用一棵树表示，树根的编号就是整个集合的编号，每个节点存储它的父节点。 p[x]表示x 的父节点。

问题1：如何判断树根： if(p[x]==x)
问题2：如何求x的集合编号， while (p[x]!= x) x = p[x]
问题3：如何合并
路径压缩：每次访问到根节点后，都会重新把这些子孙节点更新为子节点

```c++
#include <iosteam>

const int N = 10010;
int n, m;
int p[N];

int find(int x ) // 返回x 的祖宗节点 + 压缩优化
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];

}


int main()
{
    scanf("%d%d", &n, &m)
    for(int i = 1; i <= n ; i++) p[i] = i;
    while (m--)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a,&b);
        if (op[0] == 'M') p[find(a)] = p[find(b)];
        else
        {
            if (find(a)==find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
```

## 堆

手写堆。 维护一个数据集合
1. 插入一个数
2. 求这个集合的最小值
3. 删除最小值
4. 删除任意一个元素
5. 修改任意一个元素
基本结构： 二叉树
小根堆： 每个点都小于等于左右儿子。因此堆顶是最小值
存储方式：一维数组。 根节点存在1号位， x的左儿子 2x， 右儿子 2x+1
操作：`down(x)` , `up(x)` 

堆排序
1. 建堆  插入建堆是$nlog(n)$ 从n/2开始插入，复杂度是$o(n)$
2. 输出堆
```c++
#include <iostream>
#include <algorithm>
const int N;
int h[N],size;
int n,m;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1 ;i <= n ; i ++) scanf("%d",&h[i]);
    for(int i = n/2;i;i--) down(i); 
}
