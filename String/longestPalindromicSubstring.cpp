/*
    Given a string s, return the longest palindromic substring in s.

    Example 1:
      Input: s = "babad"
      Output: "bab"
      Explanation: "aba" is also a valid answer.
    
    Example 2:
      Input: s = "cbbd"
      Output: "bb"
*/

string longestPalindrome(string s) {
    int n = s.length();
    int dp[n][n];

    int p=0,q=0;

    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0){
                dp[i][j]=1;
            }
            else if(g==1){
                if(s[i]==s[j]){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=0;
                }
            }
            else{
                if(s[i]==s[j]){
                    dp[i][j]= dp[i+1][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
            if(dp[i][j]){
                p=i;
                q=j;
            }
        }
    }

    return s.substr(p,q-p+1);
}

// Time Complexity = O(n^2)
