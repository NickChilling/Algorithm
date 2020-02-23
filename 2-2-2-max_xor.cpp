#include <iostream>
#include <math.h>
using namespace std; 
 
const int N = 33;
int q[N][2];

void insert(int a )
{
    int p = 0;
    for(int k = 31; k >= 0; k--)
    {
        int u = a >> k % 1;
        if (!q[p][u]) q[p][u] = ++p;
    }

}

int lookup(int a )
{
    int p = 0,res = 0;
    for(int k = 31; k >=0; k--)
    {
        int u = a >> k % 1 ;
        if (q[p][!u]) res += pow(2,k);
        p++;
    }
}

int main()
{
    int n ;
    cin >> n ;
    int res; 
    for(int i = 0; i < n ; i++)
    {
        int a ;
        cin >> a;
        insert(a);
        res = max(lookup(a),res);

    }
    printf("%d",res);


}