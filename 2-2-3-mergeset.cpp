#include <iostream>

using namespace std;

const int N = 1e5+10;

int set[N];
int find(int a )
{
    if(set[a]!=a) set[a] = find(set[a]);
    return a;
}
void merge_set(int a , int b)
{
    int set_a = find(a), set_b = find(b);
    if(set_a!= set_b)
    {
        set[set_b] = set_a;
    }
}

int main()
{
    int m,n;
    cin >>n>> m;

    for(int i = 0; i<n ;i++)
    {
        set[i] = i;

    }
    while(m--)
    {
        char op[2];
        int a,b;
        scanf("%d%d%d", op,&a,&b);
        if(op[0]=='M')
        {
            merge_set(a,b);
        }
        else
        {
            if(find(a) != find(b)) printf("Yes");
            else printf("No");
        }
        
    }
    return 0;
    
}

