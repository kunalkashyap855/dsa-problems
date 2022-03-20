/*
    Given an integer array nums of unique elements, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:
      Input: nums = [1,2,3]
      Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

void bt(vector<int>& nums, vector<vector<int> >& ans, vector<int>& subset, int i) {
    if(i >= nums.size()) {
        ans.push_back(subset);
        return;
    }

    subset.push_back(nums[i]);
    bt(nums, ans, subset, i+1);

    subset.pop_back();
    bt(nums, ans, subset, i+1);

}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> > ans;
    vector<int> subset;

    bt(nums, ans, subset, 0);

    return ans;
}

// Time Complexity = O(n*2^n) <= This is the most efficient way to solve this problem.
