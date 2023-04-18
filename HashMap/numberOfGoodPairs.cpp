/*
    Given an array of integers nums, return the number of good pairs.
    A pair (i, j) is called good if nums[i] == nums[j] and i < j.

    Example 1:
      Input: nums = [1,2,3,1,1,3]
      Output: 4
      Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
    
    Example 2:
      Input: nums = [1,1,1,1]
      Output: 6
      Explanation: Each pair in the array are good.
*/

int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> my_map;

    for(int i = 0; i < nums.size(); i++) {
        if(my_map.count(nums[i]) > 0)
            my_map[nums[i]]++;
        else my_map[nums[i]] = 1;
    }

    int good_pairs = 0;
    for(auto i = my_map.begin(); i != my_map.end(); i++) {
        int n = i->second;
        if(n > 1)
            good_pairs += (n*(n-1))/2;
    }

    return good_pairs;
}
  
// Time Complexity = O(n)
