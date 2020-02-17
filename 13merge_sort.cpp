#include <iostream>

using namespace std;

const int N = 100010;
int q[N];
int tmp[N];

void merge_sort(int nums[], int start, int end)
{
    int mid = start + end >> 1;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid+1,end);
    int i=start,j=mid+1,k = 0;
    while( i<=mid && j <= end)
    {
        if (nums[i]<nums[j])
        {
            tmp[k++] = nums[i++];
        }
        else tmp[k++] = nums[j++];
    }
    while( i<= mid)
    {
        tmp[k++] = nums[i++];
    }
    while( j<= end)
    {
        tmp[k++] = nums[j++];
    }
    for(int l = start,m=0; l <=end; l++,m++)
    {
        nums[l]= tmp[m];
    }
    
}



int main()
{
    int n ;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",q[i]);
    }
    merge_sort(q, 0, n-1);
    for(int i = 0; i < n; i++)
    {
        printf("%d",q[i]);
    }
}