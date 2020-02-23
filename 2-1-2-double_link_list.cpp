#include <iostream>

using namespace std;

const int N = 1e5+10;

int va[N],l[N],r[N];
int head,tail;
int allocater;
void init()
{
    head = 0;
    tail = 0;
    allocater = 1;
    l[tail] = -1;
    r[tail] = -1 ;

}

void add(int k, int x)
{
    va[allocater] = x;
    r[allocater] = r[k];
    l[allocater] = k;
    l[r[k]] = allocater;
    r[k] = allocater;
    
    if (r[allocater]== -1 ) tail = allocater;
    allocater ++;


}
void del(int k)
{
    if (tail == k) tail = l[k];
    l[r[k]] = l[k];
    r[l[k]] = r[k];
    
}
void left_add(int k, int x)
{
    va[allocater] = x ;
    l[allocater] = l[k];
    r[allocater] = k;
    r[l[k]] = allocater;
    l[k] = allocater;
    allocater ++;

}

int main()
{
    init();
    int m;
    cin >> m ;
    string op;
    int k, x;
    while(m--)
    {
        cin >> op;
        if (op == "L") 
        {cin >> x ; add(head, x);}
        else if (op == "R")
        {
            cin >> x;
            add(tail, x);
        }
        else if (op == "D")
        {
            cin >> k;
            del(k);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            left_add(k, x);

        }
        else if (op == "IR")
        {
            cin >> k>>x;
            add(k, x);
        }
    }
    int p = 0;
    while(r[p]!=-1)
    {
        p = r[p];
        cout << va[p]<<' ';
    }
}