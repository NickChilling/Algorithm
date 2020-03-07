## 高斯消元
求解线性方程组， O(n^3)求解n个方程n个未知数的多元方程组
解有三种可能 无解， 无穷多解， 唯一解

高斯消元步骤：
枚举每一列
    找到绝对值最大的一行
    把这行换到最上面
    将这一行第一个数变成1
    将下面所有行消成0
    这一行固定

```c++
#include <iostream>
#include <algorithm>
#include <math>
using namespace std;

const int N = 110;
int n ;
double a[N][N];
const double eps = 1e6
//三种返回值 唯一解、无穷解、无解
int gauss()
{
    int c ,r ;
    for(c= 0,r=0; c<n; c++)
    {
        int t =r ;
        for(int i=r; i<n; i++)
        {
            if(fabs(a[i][c]) > fabs(a[t][c]))
                t=i;
        }
        if (fabs(a[t][c])<eps) continue;

        for(int i = c ; i<=n ; i++) swap(a[t][i],a[r][i]);
        for(int i = n; i>=c; i -- ) a[r][i] /= a[r][c];
        for(int i =r+1; i<n; i++)
        {
            if(fabs(a[i][c]) >eps)
                for(int j = n ; j>=c;j--)
                    a[i][j] -= a[r][j] *a[i][c];
        }
        r++;
    }
    if(r<n)
    {
        for(int i = r; i<n;i++)
            if(fabs(a[i][n]) >eps)
                return 2;
            return 1;
    }
    for(int i = n-1 ; i>=0; i--)
        for(int j = i+1; j<n ; j++)
            a[i][n] -= a[i][j]*a[j][n]
    return 0;
}


int main()
{
    cin >> n;
    for(int i = 0; i <n ; i++)
    {
        for(int j = 0; j< n ; j++)
            cin>>a[i][j]
    }
    int t = guass();
    if(t== 0)
    {

    }

    else if (t==1) puts("infinite");
    else puts("No solution");
    return 0;
}
```
## 求组合数
求组合数要根据数据范围来选算法
$C^b_a = C^b_{a-1} + C^{b-1}_{a-1}$
```c++
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2010, mod = 1e9+7;

void init()
{
    for(int i =0 ; i<N; i++)
    {
        for(int j =0 ; j<=i; j++)
        {
            if(!j) c[i][j] = 1 ; 
            else c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod ;
        }
    }
}
int main()
{
    init();
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a ,b;
        scanf("%d%d",&a, &b);
        printf("%d\n",c[a][b]);
    }

    return 0;
}
```

`1<b<a<1e5` ; 把阶乘预处理出来
因为 $a\over b mod c \neq {a mod c} \over {b mod c }$
$C_a^b = fact(a) * infact(b-a) * infact(b)$
```c++
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 10010; mod = 1e9+7;
int fact[N], infact[N];

int qmi(int a , int k , int p)
{
    int res = 1;
    while(k)
    {
        if(k&1) res = (LL) res*a%p.
        a = (LL) a*a %p;
        k >>=1;
    }
}
int main()
{
    fact[0] = infact[0] -1;
    for(int i =1; i< N; i++)
    {
        fact[i] = (LL) fact[i-1]*i%mod;
        infact[i] = (LL) infact[i-1]*qmi(i,mod-2,mod) %mod;
    }
}
```
只有20组询问，但 `1<=b<=a<= 1e18` 卢卡斯定理
$C_a^b = C_{a mod p}^{b mod p} C_{a/p}^{b/p} mod p$
```c++
#include <iostream>
#include <algorithm>
int qmi(int a, int k)
{
    int res = 1;
    while(k)
    {
        if(k%1) res = (LL) res*a %pl
        a = (LL)a*a%p;
        k >>=1;
    }
    return res;
}
int C(int a, int b)
{
    int res =1;
    for(int i=1,j=a; i<=b; i++,j--)
    {
        res = (LL) res *j %p;
        res = (LL) rse *qmi(i,p-2)%p;
    }
    return res;
}
LL lucas(int a ,int b)
{
    if (a < p && b <p) return C(a,b);
    return (LL)C(a%p,b%p)*lucas(a/p,b/p)%p;
}
int main()
{
    int n ;
    cin >> n ;
    while(n--)
    {
        LL a ,b;
        cin >> a >> b>>p;

    }
}
``` 
大数运算 求组合数。
1. 分解质因数
2. c
```c++
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5010;

int primes[N],cnt;
int sum[N];
bool st[N];
int get(int n , int p )
{
    int res = 0;
    while(n)
    {
        res += n/p;
        n/=p;
    }
    return res;
}
int main()
{
    for(int i = 0; i <cnt; i++)
    {
        int p = primes[i];
        sum[i] = get(a)- get(b)-get(a-b);
    }
    vector<int> res;
    res.push_back()
}
```
卡特兰数

$C_{a}$
```c++
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;
int qmi(int a , int b, int p )
{
    int res = 1;
    while(k)
    {
        if(k%1) res = (LL) res * a %p;
        a = (LL) a*a%p;
        k >>=1;
    }
    return res;
}


int main()
{
    int n ;
    cin >> n; 
    int a = 2*n , b=n;
    for(int i = a ; i >a-b;i--) res = (LL) res*i%mod;
    for(int i = 1; <=b ; i++) res = (LL) res*qmi(i, mod-2,mod)%mmod;
    res = (LL) res *qmi(n+1,mod-2,mod)%mod;
    

}
## 容斥原理