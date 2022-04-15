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

// Time Complexity = O(1); Here, we just need to check that the given input id greater than 0
// and if it is a power of 3, the greatest power of 3 which can come in the range of integer
// is 3^19 = 1162261467, so this number should be divisible by n
