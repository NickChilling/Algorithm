## hash 表

### 存储

1. 开放寻址法
直接mod 数字数量 。 

2. 拉链法
```c++
// 拉链法
# include <iostream>
using namespace std;
const int N = 1e5+3;
int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x %N +N) %N;
    e[idx] = x , ne[idx] = h[k], h[k] = idx ++;
    // 这里是用头插法

}
bool find(x)
{
    int k = (x % N + N) %N; // c++ 中 复数mod
    int p = h[k];
    while(p != -1 && e[k] != x) p = ne[p];

    
}

int main()
{
    int n ;
    scanf("%d", &n)
    memset(h, -1 , sizeof(h));
    while (n--)
    {
        char op[2];
        int x ;
        scanf("%s%d",op, &x);

        if(*op == 'I') insert(x);
        else
        {
            if(find(x)) puts("Yes");
            else puts("No)
        }
    }
}
```

```c++
//开放寻址法
int find()

```
### 常用字符串hash 的方式
把字符串看作是p进制的数。p是单个字符的取值范围
注意：
1. 不能映射成0
2. 假定不存在冲突 p =131  或 13331  q = 2^64 99.99的情况下，不存在冲突。

字符串前缀hash
h[i] 前i个字符串的hash值

用unsigned long long 存储 相当于mod上一个2^64

```c++
#include <iostream>
using namespace std; 

typedef unsigned long long ULL;
const int  N = 100010;

int n ,m; 
char str[N];
ULL h[N], p[N];



int main()
{
    scanf("%d%d%s", &n , &m, str+1);
    p[0] = 1;
    for (int i = 1; i<=n; i++)
    {
        p[i] = p[i-1] *p;
        h[i] = h[i-1] * p +str[i];
 
    }
    while(m--)
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &rl, &l2, &r2);
        if(get(l1,r1) == get(l2,r2) puts("Yes"));
        else puts("No");
    }
}
```
## STL 
### vector
变长数组 
### string
### queue , priority_queue
### stack
### deque
### set , map , multiset, multimap
### unordered_set, unordered_map, unordered_multiset, unorderedset
### 