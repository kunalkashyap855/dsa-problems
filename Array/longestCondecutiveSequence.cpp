/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    You must write an algorithm that runs in O(n) time.

    Example 1:
      Input: nums = [100,4,200,1,3,2]
      Output: 4
      Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

// Sorting Solution -> O(nlogn)
int longestConsecutive(vector<int>& nums) {
    if(nums.size() <= 1)
        return nums.size();

    int ans = 1;

    sort(nums.begin(), nums.end());
    int i = 0;
    int j = 1;

    int count = 1;
    while(i < nums.size() && j < nums.size()) {
        if(nums[j] - nums[j-1] == 1) {
            j++;
            count++;
        } else if(nums[j] == nums[j-1]) {
            j++;
        } else {
            i = j++;
            if(count > ans)
                ans = count;
            count = 1;
        }
    }

    if(count > ans)
        return count;

    return ans;
}

// HashSet solution -> O(n)
int longestConsecutive(vector<int>& nums) {
    if(nums.size() <= 1)
        return nums.size();

    int ans = 1;

    set<int> mySet;
    for(int i = 0; i < nums.size(); i++) {
        if(mySet.count(nums[i]) == 0)
            mySet.insert(nums[i]);
    }

    for(int i = 0; i < nums.size(); i++) {
        if(mySet.count(nums[i]-1) == 0) {
            int count = 1;
            while(mySet.count(nums[i] + count) == 1)
                count++;
            ans = max(ans, count);
        }
    }

    return ans;
}
