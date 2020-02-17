#include<iostream>

using namespace std;

const int N = 1000010;
int nums[N];

int bisearch_left(int nums[], int start, int end, int s)
{
    if (start >=end) return start;
    int mid = start + end >> 1;
    if (nums[mid]>=s)
    {
        return bisearch_left(nums, start, mid, s);
    }
    else return bisearch_left(nums, mid+1,end,s);

}
int bisearch_right(int nums[], int start, int end, int s )
{
    if (start >= end) return start;
    int mid = start + end+1 >> 1;
    if (nums[mid] <= s )
    {
        return bisearch_right(nums, mid, end, s);
    }
    else return bisearch_right(nums,start, mid-1, s);
}


int main()
{
    int q,n;
    scanf("%d %d",&n,&q);
    for(int i = 0 ; i < n; i++) scanf("%d",&nums[i]);
    int q_0 = 1;
    int query;
    while(q_0<= q)
    {
        scanf("%d",&query);
        int left = bisearch_left(nums,0,n-1,query);
        int right = bisearch_right(nums,0,n-1,query);
        if (nums[left]< query){printf("-1 -1");}
        else{printf("%d %d",&left, &right)}
    }
}