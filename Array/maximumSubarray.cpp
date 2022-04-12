/*
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
    A subarray is a contiguous part of an array.

    Example 1:
      Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
      Output: 6
      Explanation: [4,-1,2,1] has the largest sum = 6.
    
    Example 2:
      Input: nums = [1]
      Output: 1
*/

int maxSubArray(vector<int>& nums) {
    int ans = nums[0];
    int currSum = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(currSum < 0)
            currSum = 0;
        currSum += nums[i];

        ans = max(ans, currSum);
    }

    return ans;
}

// Time Complexity = O(n)
