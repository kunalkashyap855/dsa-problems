/*
    Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing 
    the relative order of the remaining characters.
    
    For example, "ace" is a subsequence of "abcde".
    A common subsequence of two strings is a subsequence that is common to both strings.

    Example 1:
      Input: text1 = "abcde", text2 = "ace" 
      Output: 3  
      Explanation: The longest common subsequence is "ace" and its length is 3.
*/

// DP Approach
int longestCommonSubsequence(string text1, string text2) {
    int lcs[text1.size()+1][text2.size()+1];

    for(int i = 0; i <= text2.size(); i++)
        lcs[0][i] = 0;

    for(int i = 0; i <= text1.size(); i++)
        lcs[i][0] = 0;

    for(int i = 1; i <= text1.size(); i++) {
        for(int j = 1; j <= text2.size(); j++) {
            if(text1[i-1] == text2[j-1])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }

    return lcs[text1.size()][text2.size()];
}

// Time Complexity = O(n^2)
