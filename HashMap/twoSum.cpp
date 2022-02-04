/*
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.
*/

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;

    unordered_map<int, int> mymap;
    for(int i = 0; i < nums.size(); i++) {
        int temp = target - nums[i];
        if(mymap.count(temp) == 1) {
            ans.push_back(mymap[temp]);
            ans.push_back(i);
            return ans;
        } else {
            mymap[nums[i]] = i;
        }
    }

    return ans;
}

// Time Complexity = O(n) /// Hashmaps take O(1) time for retrieval and insertion of elements.
