/*
    Write a function that reverses a string. The input string is given as an array of characters s.
    You must do this by modifying the input array in-place with O(1) extra memory.

    Example 1:
      Input: s = ["h","e","l","l","o"]
      Output: ["o","l","l","e","h"]
    
    Example 2:
      Input: s = ["H","a","n","n","a","h"]
      Output: ["h","a","n","n","a","H"]
*/

void reverseString(vector<char>& s) {
    char* left = &s[0];
    char* right = &s[0] + (s.size()-1);

    while(left < right) {
        swap(*left, *right);
        left++;
        right--;
    }
}

// Time Complexity = O(n); Space Complexity = O(1)
