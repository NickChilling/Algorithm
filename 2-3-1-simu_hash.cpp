#include <iostream>
#include <cstring>
using namespace std;

// 拉链法
const int N = 1e5+3;
int null = 0x3f3f3f3f;
int alloc,h[N],e[N], ne[N];


//set memory  -1 
void insert(int a )
{
    int hv = ((a % N) + N) % N;
    e[++alloc] = a;
    ne[alloc] = h[hv];
    h[hv] = alloc;
}

bool lookup(int a )
{
    int hv = ((a % N ) + N) % N;
    
    for(int p = h[hv]; p != -1; p = ne[p])
    {
        if (e[p] == a) return true;
    }
    return false;
}
// 开放寻址法
void insert_open(int a )
{
    int hv = (a % N +N) % N;
    while(h[hv] != null) hv ++;
    h[hv] = a ;
}
bool query_open(int a )
{
    int hv = (a%N +N) %N;
    for(int i = hv; h[i]!=null; i++)
    {
        if (h[i] = a ) return true;
        
    }
    return false;
}

int main()
{
    char op[2];
    int x ;
    int n ; 
    cin >> n;
    memset(h, -1 , sizeof h);
    while(n--)
    {
        scanf("%s%d",op, &x);
        if (op[0] == 'I') insert(x);
        if(op[0] == 'Q')
        {
            if (lookup(x)) puts("Yes");
            else puts("No");
        }
    }
}