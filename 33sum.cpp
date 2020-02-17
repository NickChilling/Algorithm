#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3e4+10;
int a[N],s[N];

vector<int> alls;
typedef pair<int, int> PII;

vector<PII> add ,query;

int find(int x )
{
    int l = 0, r = alls.size() - 1;

    while(l < r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x)
        {
            r = mid;
        }
        else l = mid + 1;

    }
    return r+1;  // 为什么这里是r+1
}  // find 其实相当于映射， r 是下标，如果要放到a数组里需要加1；

int main()
{
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        int x ,c;
        cin >> x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    while(m--)
    {
        int l,r ;
        cin >> l >> r;
        query.push_back({l,r});

        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    
    for(auto item :add)
    {
        int x = find(item.first); // 找到大于item.first 的位置
        a[x] += item.second;

    }
    for(int i = 1; i<= alls.size();i++)
    {
        s[i] = s[i-1] + a[i];
    }
    for(auto item:query)
    {
        int l = find(item.first), r = find(item.second);
        cout<< s[r] - s[l-1] << endl;
    }
}