/*
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

    Example 1:
      Input: s = "A man, a plan, a canal: Panama"
      Output: true
      Explanation: "amanaplanacanalpanama" is a palindrome.
*/

bool isPalindrome(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(isupper(s[i]))
            s[i] = tolower(s[i]);

        if(!isalnum(s[i])) {
            s.erase(i,1);
            i--;
        } else if(s[i] == ' ') {
            s.erase(i,1);
            i--;
        }

    }

    for(int i = 0; i < (s.size()/2); i++) {
        if(s[i] != s[s.size()-1-i])
            return false;
    }

    return true;
}

// Time Complexity = O(n)
