/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.86%)
 * Likes:    3596
 * Dislikes: 80
 * Total Accepted:    307.9K
 * Total Submissions: 735.4K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */
#include <vector>
#include<iostream>
using namespace std;

// @lc code=start

// dp 题目
// 状态：dp[i] 考虑了第i个为子序列，这样状态没办法转移。d[i]和dp[i+1]没有任何关系
// 状态应该是将第i个作为子序列。对于dp[i] 遍历i之前的元素。如果这个元素比a[i]小。那么就是dp[i] = dp[j]+1
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n==0){
            return 0;
        }
        int LIS = 1;
        vector<int> dp(n,1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                    LIS = max(dp[i],LIS);
                }
            }
        }
        return LIS;
    }
};
// int main(){
//     vector<int> testcase {10,22,9,33,21,50,41,60,80};
//     int res = Solution().lengthOfLIS(testcase);
//     cout<<res<<endl;
//     return 0;
// }
// @lc code=end
