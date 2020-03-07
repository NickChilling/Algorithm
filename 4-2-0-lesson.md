## 欧拉函数
什么是欧拉函数
$\Fi(n)$ 表示1-n中与n互质的数的个数
$\Fi(6)$ = [1,6].count() 
$ N = p_1

n 有k个质因子。 
1. 从1-n中去掉 p1,p2...pk的所有倍数
  1-n 中 p1的倍数的个数。
  n - n/p1 - n/p2 -.... n/pk
2. 会有数会多去一次
  加上所有 pi*pj 的倍数

3. 减去所有`pi*pj*pk` 的倍数
以此类推
`- = - = - =` 
```c++
int res = a ;
for(int i = 2 ; i <= a/i ; i++)
{
    if(a %i ==0)
    {
        res = res / i *(i-1);
        while(a%i==0) a/=i;

    }
}
if (a > 0 ) res / a *（a-1);
```
筛法求欧拉函数
求出1-n 每一个数的欧拉函数 
O(n)
```c++
typedef long long LL;
int primes[N], cnt;
int bool st[N];
int phi[N];
LL get_eulers(int n)
{
    for(int i = 2; i <=n ; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i ;
            phi[i] = i-1 ; // 如果i是质数， 那么它前面的所有数都和他互质。
        }
        for(int j =0; primes[j] <= n /i; j++)
        {
            st[primes[j]*i] = true;
            phi[primes[j]*i] = phi[i]*(primes[j]-1)
            if(i%primes[j] == 0) 
            {
                phi[primes[j]*i] = phi[i] *primes[j];
                break;
        }
        // 加和
    }
}
int main()
{
    int n ; 
    cin >> n ;
    cout << get_eulers(n) << endl;

``` 
如果a与n互质。 则 a^\phi(n) mod n = 1 

费马定理 如果 n是一个质数 a^\(P-1) mod n = 1

快速幂
求 a^k mod p  O(logk)
预处理 a^2^0 mod p  a^2^1 mod p ......
log k 个
```c++
LL qmi(int a,int k,int p)
{
    int res= 1 ;
    while(k)
    {
        if (k & 1) res = (LL) res*a %p;
        k >> 1 ;
        a = (LL) a * a %p;
    }
}
```
a 能整除 b 。 

b * x === 1 mod m
根据费马定理
x = b^(p-2);

裴蜀定理： 
  有一对正整数a,b 那么存在整数 x,y 使得 ax+by = (a,b)最大公约数

欧几里得算法
```c++
int gcd(int a , int b, int &x, int &y)
{
    if (!b) 
    {
        x = 1, y = 0;    
        return a;
    }
    int d = gcd(b, a%b, y, x);
    y -= a /b *x;
    return d;
}
``` 
线性同余方程。 ax=== b mod m 

中国剩余定理， 给定一堆 两两互质的