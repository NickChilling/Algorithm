# 链表、栈、与KMP

## 链表
### 构造
面试通常用指针+结构体，但速度太慢
```c++
struct Node
{
    int val;
    Node *link;
}
```

比赛通常用数组模拟链表

1. 单链表： 邻接表 - 存储图和树；
2. 双链表： 优化某些问题； 


```c++
#include <iostream>
using namespace std ;
const int N = 100010;

//head表示头节点的下标
// e[i] 表示节点i 的值
//ne[i] 表示节点i的next指针是多少
// idx 存储当前用到的哪个点
int head, e[N],ne[N], idx;

void init()
{
    head = -1;
    idx = 0;
}
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++ ;
}

void add(int k ;int x )
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++ ;

}
void delete(int k )
{
    ne[k] = ne[ne[k]];
}
int main()
{
    int m ;
    cin >> m;

    while (m--)
    {
        int k, x;
        char op;
        cin >> op;
        if(op == "H")
        {
            cin >>x;
            add_to_head(x);
        }
        else if (op=="O")
        {
            cin >> k;
            remove(k-1);
        }
        else
        {
            cin >>k >> x;
            add(k-1,x);

        }
    }
    for(int i = head; i != -1; i = ne[i]) cout <<e[i]<<"";
}
```

双头指针
```c++
#include <iostream>
using namespace std;

const int N = 100010;

void init()
{

}
void insert()
{

}
void delete()
{

}
```

## 模拟栈和队列
栈： 先进后出
队列： 先进先出
```c++
#include <iostream>

using namespace std;

const int N = 100010;

int stk[N],tt;
stk[ ++ tt] = x; // 进栈

tt -- ;

int queue[N],hh,tt;
// 入队
queue[ ++ tt] = x;
//出队
hh -- ;
```
## 单调栈
## 单调队列
滑动窗口的最大最小值

```c++
#include <iostream>

using namespace std; 

const int N = 100010;
int n, k ;
int a[N],q[N];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);

    int hh = 0 , tt = -1; 
    for (int i = 0; i < n ; i ++)
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++; // 当队列不空且左窗口的下标大于队头时，出队
        while( hh <= tt && a[q[tt]] >= a[i]) tt -- ; // 右移窗口 当队列不空，新来的数比队尾还小的时候，队尾出。

        if (i >= k - 1) printf("%d",a[q[hh]]);
        q[++tt] = i;
    }
}
```
## KMP 

字串的匹配

先暴力求解方法
```c++
#include <iostream>
using namespace std;

class Solution
{
    void kmp_o2(string s, string p)
    {
        int count = 0;
        for(int i = 1; i <= s.size(), i++)
        {
            bool flag = true;
            for(int j = 1; j<= p.size();j++)
            {
                if (s[i+j]!=p[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag==true) count++;
        }
    }
}
```

next[i], 以i为中点的后缀
next[i] = j 的含义是 p[1,j] = p[i-j+1,i]

```c++
#include <iostream>
using namespace std;
const int N = 10010 ; M = 100010;

int n, m ;
char p[N],s[M];
int ne[N];

int main()
{
    cin >> n >> p+1 >> m >> s+1;

    //  求next 
    for(int i = 2 ,j = 0; i <= n; i ++)
    {
        while(j && p[i]!=p[j+1]) j = ne[j];
        if (p[i] == p[j+1]) j++;
        ne[i] = j;
    }
    for(int i =1 ; j = 0; i <= m ; i++)
    {
        while(j && s[i] != p[j+1] j = ne[j])
        if(s[i] == p[j+1]) j++;
        if(j==n)
        {
            printf("%d", i-n);// 题目中下标是从0开始
            j = ne[j]   //匹配成功
        }
    }
}
```