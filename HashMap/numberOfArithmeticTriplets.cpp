/*
    You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. 
    A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
      i < j < k,
      nums[j] - nums[i] == diff, and
      nums[k] - nums[j] == diff.
      Return the number of unique arithmetic triplets.

    Example 1:
      Input: nums = [0,1,4,6,7,10], diff = 3
      Output: 2
      Explanation:
      (1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
      (2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. 
*/

int arithmeticTriplets(vector<int>& nums, int diff) {
    unordered_map<int, bool> umap;
    int count = 0;

    for(int i = 0; i < nums.size(); i++) {
        int n = nums[i];
        if(umap[n-(2*diff)] && umap[n-diff])
            count++;
        umap[n] = true;
    }

    return count;
}
  
// Time Complexity = O(n)
