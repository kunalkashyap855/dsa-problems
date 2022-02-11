/*
    Given an integer array nums, return the length of the longest strictly increasing subsequence.
    A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 
    For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

    Example 1:
      Input: nums = [10,9,2,5,3,7,101,18]
      Output: 4
      Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

int lengthOfLIS(vector<int>& nums) {
    if(nums.size() <= 1)
        return nums.size();

    int dp[nums.size()+1];
    for(int i = 0; i <= nums.size(); i++)
        dp[i] = 1;
    dp[0] = 0;

    int maxLength = 1;
    for(int i = 2; i <= nums.size(); i++) {
        for(int j = 0; j < i-1; j++) {
            if(nums[i-1] > nums[j]) {
                dp[i] = max(dp[i], 1+dp[j+1]);
            } 
        }
        if(dp[i] > maxLength)
            maxLength = dp[i];
    }

    return maxLength;
}

// Time Complexity = O(n^2)
