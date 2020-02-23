#include <iostream>
using namespace std;

const int N = 1e5+10;
int a[N], s;

void up(int k)
{
    while( k/2 && a[k/2]>a[k])
    {
        swap(a[k],a[k/2]);
        k >>= 1;
    }

}
void down(int u)
{
    int t = u;
    if (u * 2 <= s && a[u*2] <a[t]) t = u *2;
    if( u*2+1 <= s && a[u*2+1] <a[t]) t= u*2+1;
    if(u !=t)
    {
        swap(a[u], a[t]);
        down(t);
    }
}


int main()
{
    int n , m;
    cin >> n >> m;
    s = n;
    for(int i = 1 ; i <=n ; i ++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = n/2; i > 0; i--)
    {
        down(i);
    }
    while(m--)
    {
        printf("%d",a[1]);
        swap(a[1],a[s]);
        s -- ;
        down(1);
    }
    return 0;
}