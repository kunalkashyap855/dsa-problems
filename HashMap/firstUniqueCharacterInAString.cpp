/*
    Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
    
    Example 1:
      Input: s = "leetcode"
      Output: 0
*/

int firstUniqChar(string s) {
    unordered_map<char, int> umap;
    for(int i = 0; i < s.size(); i++) {
        if(umap.count(s[i]) > 0)
            umap[s[i]]++;
        else umap[s[i]] = 1;
    }


    for(int i = 0; i < s.size(); i++) {
        if(umap[s[i]] == 1)
            return i;
    }

    return -1;
}

// Time Complexity = O(n)
