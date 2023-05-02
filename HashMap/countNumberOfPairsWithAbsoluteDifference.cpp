/*
    Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
    The value of |x| is defined as:
      x if x >= 0.
      -x if x < 0.

    Example 1:
      Input: nums = [1,2,2,1], k = 1
      Output: 4
      Explanation: The pairs with an absolute difference of 1 are:
      - [1,2,2,1]
      - [1,2,2,1]
      - [1,2,2,1]
      - [1,2,2,1]
    
    Example 2:
      Input: nums = [1,3], k = 3
      Output: 0
      Explanation: There are no pairs with an absolute difference of 3.
*/

int countKDifference(vector<int>& nums, int k) {
    unordered_map<int, int> occurences;
    for(int i = 0; i < nums.size(); i++) {
        if(occurences.count(nums[i]))
            occurences[nums[i]]++;
        else occurences[nums[i]] = 1;
    }

    int ans = 0;
    for(auto itr = occurences.begin(); itr != occurences.end(); ++itr) {
        cout<<itr->first<<" - "<<itr->second<<endl;
        if (occurences.count((itr->first + k))) {
            ans += (itr->second * occurences[(itr->first + k)]);
            if(!occurences.count(itr->first - k))
                itr->second = 0;
        }
    }

    return ans;
}
  
// Time Complexity = O(n)
