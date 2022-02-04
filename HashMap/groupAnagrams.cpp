/*
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

    Example 1:
      Input: strs = ["eat","tea","tan","ate","nat","bat"]
      Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> umap;

    for(int i = 0; i < strs.size(); i++) {
        string temp = strs[i];
        sort(strs[i].begin(), strs[i].end());
        umap[strs[i]].push_back(temp);
    }

    for(auto itr=umap.begin(); itr != umap.end(); ++itr) {
        ans.push_back(itr->second);
    }

    return ans;
}

/* 
    We create a HashMap in which the key is the sorted string and value is an array actual strings that correspong to that sorted string (they are anagrams).
    Time Complexity = O(nklogk) <= klogk is because of sorting the longest string of length k and n is because of for loop.
*/
