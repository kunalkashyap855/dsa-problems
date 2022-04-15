/*
    Given an integer n, return true if it is a power of three. Otherwise, return false.
    An integer n is a power of three, if there exists an integer x such that n == 3x.

    Example 1:
      Input: n = 27
      Output: true
    
    Example 2:
      Input: n = 0
      Output: false
*/

// Without using loop or recursion
bool isPowerOfThree(int n) {
    return (n > 0 && 1162261467 % n == 0);
}

// Time Complexity = O(1)
