#include <iostream>
#include <algorithm>

using namespace std; 

int get_eulers(int a )
{
    int res = a;
    for(int i = 2 ; i <= a/ i; i++)
    {
        if( a % i == 0)
        {
            res = res / i *(i-1); // 先除再乘是为了防止溢出
            while(a%i ==0) a/=i;
        }
        
    }
    if(a > 1) res = res/a*(a-1);
    return res;
}
int main()
{
    int n ; 
    cin >> n ;
    while(n--)
    {
        int a;
        cin >> a;
        int res = get_eulers(a);
        cout<< res;
    }
}