#include <iostream>

using namespace std; 

const int N = 1e5+10;

int q[N],s[N];

int main()
{
    int n ; 

    scanf("%d", &n);
    for(int i = 0 ; i < n; i++)
    {
        scanf("%d", &q[i]);
    }
    int j = 0, res = 0;
    for(int i = 0; i < n; i++)
    {
        s[q[i]] ++;
        while(j <= i && s[q[i]] > 1 )
        {
            s[q[j]] -- ;
            j ++;
        }
        res = max(res, i-j+1);

    }
    cout << res <<endl;
    return 0 ;

}