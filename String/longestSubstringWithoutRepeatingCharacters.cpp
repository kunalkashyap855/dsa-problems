/*
    Given a string s, find the length of the longest substring without repeating characters.

    Example 1:
      Input: s = "abcabcbb"
      Output: 3
      Explanation: The answer is "abc", with the length of 3.
*/

int lengthOfLongestSubstring(string s) {
    if(s.size() == 0)
        return 0;

    int ans = 1;

    int start = 0;
    unordered_map<char, int> umap;

    for(int end = 0; end < s.size(); end++) {
        if(umap.count(s[end]) > 0) {
            int duplIndex = umap[s[end]];
            ans = max(ans, (end-start));

            for(int i = start; i <= duplIndex; i++) {
                umap.erase(s[i]);
            }

            start = duplIndex + 1;
        }

        umap[s[end]] = end;
    }

    if(ans > (s.size()-start))
        return ans;
    else return (s.size() - start);
}

// Time Complexity = O(n)
