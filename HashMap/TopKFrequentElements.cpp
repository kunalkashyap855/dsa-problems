/*
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

    Example 1:
      Input: nums = [1,1,1,2,2,3], k = 2
      Output: [1,2]
    
    Example 2:
      Input: nums = [1], k = 1
      Output: [1]
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
      if(nums.size() == 1)
          return nums;

      unordered_map<int, int> umap;

      for(int i = 0; i < nums.size(); i++) {
          if(umap.count(nums[i]) > 0)
              umap[nums[i]]++;
          else umap[nums[i]] = 1;
      }

      priority_queue<pair<int, int> > pq;
      for(auto itr = umap.begin(); itr != umap.end(); ++itr) {
          pq.push(make_pair(itr->second, itr->first));
      }

      vector<int> ans;
      for(int i = 1; i <= k; i++) {
          ans.push_back(pq.top().second);
          pq.pop();
      }

      return ans;
  }

// TIME COMPLEXITY = O(n)
