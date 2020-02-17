#include <iostream>
///这道题要用longlong
using namespace std;
typedef long long LL;
const int N = 1000010;
int q[N];
int tmp[N];
int reverse_pair(int nums[], int start, int end)
{
    if (start >= end)
        return 0;
    int left_reverse, right_reverse, cross_reverse = 0;
    int mid = start + end >> 1,i = start, j = mid+1,k=0;
    left_reverse = reverse_pair(nums, start, mid);
    right_reverse = reverse_pair(nums, mid + 1, end);
    while(i<=mid && j <= end)
    {
          if(nums[i]<=nums[j]) tmp[k++] = nums[i++];
          else 
          {tmp[k++] = nums[j++];cross_reverse++;}

    }
    while(i<=mid) tmp[k++] = nums[i++];
    while(j<=end) tmp[k++] = nums[j++];
    for(int i=start,j=0;i<=end;j++,i++) nums[i] = tmp[j];
    return left_reverse+right_reverse+cross_reverse;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    int res;
    res = reverse_pair(q, 0, n - 1);
    printf("%d", res);
    return 0;
}