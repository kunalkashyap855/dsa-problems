/*
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
    such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    Example 1:
      Input: nums = [-1,0,1,2,-1,-4]
      Output: [[-1,-1,2],[-1,0,1]]
    
    Example 2:
      Input: nums = []
      Output: []
    
    Example 3:
      Input: nums = [0]
      Output: []
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for(int i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        int left = i+1, right = nums.size()-1;
        while(left < right) {
            int threeSum = nums[i] + nums[left] + nums[right];

            if(threeSum > 0)
                right--;
            else if(threeSum < 0)
                left++;
            else {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;

                while(nums[left] == nums[left-1] && left < right)
                    left++;
            }
        }
    }

    return ans;
}

// Time Complexity = O(n^2) <= Most efficient.
