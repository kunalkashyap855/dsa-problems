/*
    Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the 
    chosen numbers sum to target. You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the
    chosen numbers is different.

    The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

    Example 1:
      Input: candidates = [2,3,6,7], target = 7
      Output: [[2,2,3],[7]]
*/

void dfs(int i, vector<int>& curr, int total, vector<vector <int>>& res, int target, vector<int>& candidates) {
    if (total == target) {
        res.push_back(curr);
        return;
    }

    if (i >= candidates.size() || total > target)
        return;

    curr.push_back(candidates[i]);
    dfs(i, curr, total + candidates[i], res, target, candidates);
    curr.pop_back();        
    dfs(i + 1, curr, total, res, target, candidates);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector <int>> res;
    vector<int> curr;

    dfs(0, curr, 0, res, target, candidates);
    return res;
}

// Time Complexity = O(2^t) <- 't' is the target.
