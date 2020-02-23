#include <iostream> 
using namespace std;

const int N = 1e5+10;
int h[N],ph[N],hp[N], s,p;

void swap_heap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);  // 
    swap(hp[a],hp[b]);  // hp h: position
    swap(h[a],h[b]);  /// h 记录的是 位置 ab
}

void up(int k)
{
    while ( k/2 && h[k/2] > h[k])
    {
        swap_heap(k, k/2);
        k >>= 1;
    }
}
void down(int k )
{
    int t = k;
    if(2*k <= s && h[2*k] < h[t]) t = 2*k;
    if(2*k+1 <= s && h[2*k+1] < h[t]) t = 2*k +1;
    if (k != t)
    {
        swap_heap(k, t);
        down(t);
    }

}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
    }
    s = n;
    for(int i = s/2 ; i >0; i-- )
    {
        down(i);        
    }
    while(m--)
    {
        string op;
        int k,x;
        cin >> op;
        if(op == "I")
        {
            cin >> x;
            h[++s] = x;
            hp[s] = ++p;
            ph[p] = s;
            up(s);
        }
        else if (op=="PM")
        {
            printf("%d",h[1]);
        }
        else if (op=="DM")
        {
            swap_heap(1, s);
            s -- ;
            down(1);
            
        }
        else if(op == "D")
        {
            cin >> k ;
            swap(ph[k],s);
            s--;
            down(ph[k]);
            
        }
        else
        {
            cin >> k >> x;
            h[ph[k]] = x;
            up(ph[k]);
            down(ph[k]);
        }
    }

}