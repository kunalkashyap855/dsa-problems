/*
    You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. 
    You can perform this operation at most k times.

    Return the length of the longest substring containing the same letter you can get after performing the above operations.

    Example 1:
      Input: s = "ABAB", k = 2
      Output: 4
      Explanation: Replace the two 'A's with two 'B's or vice versa.
    
    Example 2:
      Input: s = "AABABBA", k = 1
      Output: 4
      Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA". The substring "BBBB" has the longest repeating letters, which is 4.
*/

int characterReplacement(string s, int k) {
    int ans = 0;
    unordered_map<char, int> umap;

    int l = 0;
    for(int r = 0; r < s.size(); r++) {
        if(umap.count(s[r]) > 0)
            umap[s[r]]++;
        else umap[s[r]] = 1;

        int max = 0;
        unordered_map<char, int>:: iterator itr;
        for(itr = umap.begin(); itr != umap.end(); itr++) {
            if(itr->second > max)
                max = itr->second;
        }

        while(((r-l+1) - max) > k) {
            umap[s[l]]--;
            l++;
        }

        if(ans < (r-l+1))
            ans = r-l+1;
    }

    return ans;
}

// Time Complexity = O(n)
