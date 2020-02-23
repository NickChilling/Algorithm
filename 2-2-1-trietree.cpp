#include <iostream>

using namespace std;

const int N = 2e4+10;

int s[N][26],cnt[N], allocater;
char str[N];
void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i];i++)
    {
        int u = str[i]-'a';
        if(!s[p][u]) s[p][u] = ++ allocater;
        p = s[p][u];
    }
    cnt[p] += 1; 
}

int query(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!s[p][u]) return 0;
        p = s[p][u];
    }
    return cnt[p];
}
int main()
{
    int n;
    cin >> n ;
    char op[2];
    int res;
    while(n--)
    {
        scanf("%d%d", &op, &str);
        if (op[0] == 'I') insert(str);
        else 
        {
            res = query(str);
            printf("%d\n", res);
        }
    }
}