/*
    Given a signed 32-bit integer x, return x with its digits reversed. 
    If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

    Example 1:
      Input: x = 123
      Output: 321
    
    Example 2:
      Input: x = -123
      Output: -321
    
    Example 3:
      Input: x = 120
      Output: 21
*/

int reverse(int x) {
    int MAX = 2147483647;
    int MIN = -2147483648;

    int rev = 0; 

    while(x){ 
        if(rev > MAX / 10 || (rev == MAX / 10 && x%10 >= MAX % 10))
            return 0;

        if(rev < MIN / 10 || (rev == MIN / 10 && x%10 <= MIN % 10))
            return 0;

        rev = rev*10 + x%10; 
        x /= 10; 
    }

    return rev;
}

// Time Complexity = O(n) <= where 'n' is the number of digits in the input x
