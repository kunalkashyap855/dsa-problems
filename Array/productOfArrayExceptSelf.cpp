/*
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

    Example 1:
      Input: nums = [1,2,3,4]
      Output: [24,12,8,6]
    
    Example 2:
      Input: nums = [-1,1,0,-3,3]
      Output: [0,0,9,0,0]
*/

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;

    ans.push_back(1);

    // prefix pass
    for(int i = 1; i < nums.size(); i++) {
        ans.push_back(ans[i-1] * nums[i-1]);
    }

    // postfix pass
    int postfix = nums[nums.size()-1];
    for(int i = nums.size()-2; i >= 0; i--) {
        ans[i] = ans[i] * postfix;
        postfix *= nums[i];
    }

    return ans;
}

// Time Complexity = O(n) and Extra Space Complexity = O(1)
