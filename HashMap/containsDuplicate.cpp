/*
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

    Example 1:
      Input: nums = [1,2,3,1]
      Output: true
    
    Example 2:
      Input: nums = [1,2,3,4]
      Output: false
    */

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> umap;

    for(int i = 0; i < nums.size(); i++) {
        if(umap.count(nums[i]) > 0)
            return true;
        else umap[nums[i]] = 1;
    }

    return false;
}

// Time Complexity = O(n)
