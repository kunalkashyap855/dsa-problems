/*
    Given an array nums of size n, return the majority element.
    The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

    Example 1:
      Input: nums = [3,2,3]
      Output: 3

    Example 2:
      Input: nums = [2,2,1,1,1,2,2]
      Output: 2

    Follow-up: Could you solve the problem in linear time and in O(1) space?
*/


// Hashmap Solution - Time Complexity = O(n); Space Complexity = O(n)
int majorityElement(vector<int>& nums) {
    int majEle = 0;
    int maxCount = 0;

    unordered_map<int, int> umap;

    for(int i = 0; i < nums.size(); i++) {
        if(umap.count(nums[i]) > 0)
            umap[nums[i]]++;
        else umap[nums[i]] = 1;
    }

    for(auto itr=umap.begin(); itr != umap.end(); ++itr) {
        if(itr->second > maxCount) {
            maxCount = itr->second;
            majEle = itr->first;
        }

    }

    return majEle;
}

// Boyer Moore Algorithm Solution - Time Complexity = O(n); Space Complexity = O(1)
int majorityElement(vector<int>& nums) {
    int count = 0;
    int res = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(count == 0) {
            count++;
            res = nums[i];
        } else {
            if(nums[i] == res)
                count++;
            else count--;
        }
    }

    return res;

}
