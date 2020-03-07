## 数论

### 质数
大于1 的整数中，如果只包含1和本身这两个约束，就是质数或者素数。
#### 判定
1. 试除法
i < = n / i  不会溢出 。
2. 分解质因数
从小到大， 枚举所有数。尝试n 的所有因数。
```c++
void divide(int x )
{
    for(int i = 2 ; i< = n; i++)
    {
        if(n %i == 0 )
        {
            int s = 0;
            while(n%i==0)
            {
                s++;
                n/=i;
            }
        }
    }
    if(n >1) printf("%d", n);
}
```
n中最多只包含1个大于sqrt(n)的质因子。

2. 筛质数
逐个去筛
埃氏筛法： 只用质数去筛
线性筛法： 枚举   在
1. 正确性  合数一定会被筛掉。
n 只会被最小质因子筛掉。

```c++
#include <iostream>
using namespace std;
void get_primes(int n )
{
    for(int i = 2; i < =n ; i++)
    {
        if(!st[i]) primes[cnt++] = i ; // i是质数
        for(int j = 0 ; primes[j] <=n/i; j ++)
        {
            st[primes[j]*i] = true;
            if(i %primes[j]==0) break; // primes[j] 一定是最小质因子
        }
    }
}
``` 
i % pj == 0 ; pj 一定是i 的最小质因子， pj 一定是pj*i 的最小质因子。
i % pj != 0 ; pj 一定小于i 的所有质因子， pj也一定是pi * i的最小质因子。

试除法 求约数
```c++
vector<int> get_divisor(int n)
{
    vector<int> res;
    for(int i = 1; i <=n ; i ++)
    {
        if(n %i==0)
        {
            res.push_back();
            if(i != n/i ) res.push_back(n/i);
        }

    }
    sort(res.begin(), res.end());
    return res;
}
```

### 约数个数

### 约数之和
```c++ 
mod = 1e9+7
int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> primes;
    while(n--)
    {
        int x ; 
        cin >> x;
        for(int i = 2; i <= x/i; i++)
        {
            while(x %i ==0)
            {
                x /= i ;
                primes[i] ++;

            }

        }
        if(x > 1) primes[x] ++;
    }
    LL res = 1;
    for(auto prim: primes) res = res*(prime.second+1) %mod; // 个数

    for(auto prim:primes)
    {
        int p = prime.first, a = prime.second;
        LL t = 1;
        while(a--) t = (t*p+1);
        res += p 
    }
}
```
最大公约数
欧几里得算法， 辗转相除法
d能整除a d能整除b  那么d 就能整除 a+b 
```c++
int gcd(int a , int b)
{
    return b?gcd(b, a%b) : a;
    
}
```