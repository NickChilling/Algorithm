#include <iostream>
#include <cstring>
using namespace std ;

const int  N = 1e5+10;
int n ;
int h[N],e[N],ne[N], idx, min_;
bool st[N];
// 虽然是树， 但是没法保证从根节点遍历到叶节点
// 能保证的是， 计算方式
// 为什么需要设置st。 如果是按照从根到叶的节点顺序连接。那么不需要st，
// 因为叶节点没有到根节点的路径。但是， 在这道题中， 是按照图的方式存储。
// 所以当我们从根到叶时，还能从叶找到根。因此需要st记录状态

void add(int a, int b)
{
    e[++idx] = b; 
    ne[idx] = h[a];
    h[a] = idx;
}
int dfs(int k )
{
    st[k] = true;
    int sum = 1, res = 0; 
    for(int i = h[k]; i != -1; i= ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int s = dfs(j);
            res = max(s, res);
            sum += s;
        }
    }
    res = max(res, n-sum);
    min_ = min(min_,res);
    return sum;
}

int main()
{
    cin >> n ;
    min_ = n; 
    memset(h, -1 , sizeof h);
    for(int i = 0; i < n-1 ; i ++)
    {
        int a ,b ;
        cin >> a >> b;
        add(a,b), add(b,a);
    }
    dfs(1);
    cout<<min_;
}