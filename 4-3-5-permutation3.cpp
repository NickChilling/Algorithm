#include <iostream>

using namespace std;
typedef long long LL;
int p ;
LL qmi(int a , int k , int q )
{
    LL res = 1 ; 
    while(k)
    {
        if(k & 1) res = (LL) res * a % q;
        a = (LL) a*a % q;
        k >>=1;
    }
    return res ;
}

int C(int a, int b)
{
    int res = 1;
    for(int i = 1, j =a; i<=b;i++,j--)
    {
        res = (LL) res * j %p;
        res = (LL) res * qmi(i, p-2,p) %p;
    }
    return res;
}

int lucas(LL a , LL b)
{
    if(a<p && b<p) return C(a,b);
    return (LL)C(a%p, b%p) *lucas(a/p,b/p) %p;
}
int main()
{
    int n ;
    cin >> n; 
    while(n--)
    {
        LL a , b;
        cin >>a>>b>>p;
        cout << lucas(a,b) << endl;
    }
}