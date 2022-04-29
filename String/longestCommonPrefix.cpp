/*
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".

    Example 1:
      Input: strs = ["flower","flow","flight"]
      Output: "fl"
    
    Example 2:
      Input: strs = ["dog","racecar","car"]
      Output: ""
      Explanation: There is no common prefix among the input strings.
*/

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 1)
        return strs[0];

    string commonPrefix = "";

    // find minLength word
    int minLength = 0;
    for(int i = 0; i < strs.size(); i++) {
        if(strs[i].size() > minLength)
            minLength = strs[i].size();
    }

    // then a for loop from 0 to minLength
    // Inside this another for loop from 0 to len of input array
    // for each string, check if strs[j][i] is equal, if for any j it is not equal, return commonPrefix built till now
    // If strs[j][i] is equal for each j, add element to commonPrefix
    for(int i = 0; i < minLength; i++) {
        char currChar = strs[0][i];
        for(int j = 1; j < strs.size(); j++) {
            if(strs[j][i] != currChar)
                return commonPrefix;
        }

        commonPrefix.push_back(currChar);
    }

    return commonPrefix;
}
