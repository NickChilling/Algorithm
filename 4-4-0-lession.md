## 容斥原理

```c++
int main()
{
    cin >> n >> m;
    for(int i= 0; i <m ; i++) cin >> p[i];
    int res = 0;
    for(int i = 1 ; i< 1<<m; i++)
    {
        int t = 1, cnt = 0;
        for(int j = 0 ; j < m ; j++)
        {
            if(i >>j&1)
            {
            cnt ++;
            if((LL) t *p[j]>n)
            {
                t = -1;
                break;
            }
            t *= p[j];
            }
        }
        if(t != -1)
        {
            if(cnt %2) res += n /t;
            else res -= n/t;
        }
    }
}
```
## 博弈论
### ICG 游戏  
公平组合游戏
1. 两个玩家交替行动
2. 在任意时刻，可以执行的合法行动与轮到哪名玩家无关
3. 不能行动的玩家判负
先手 
必胜态：可以走到某一个必败状态
必败态：走不到任何一个必败状态
a1 ^ a2 ^ .... ^an = 0  先手必败
！= 0 先手必胜

异或为0 不一定所有数成对 
a_i ^ x < a_i  拿走 a_i - (a_i ^x)
那么就剩下 a_i^x 
## iCG 函数
