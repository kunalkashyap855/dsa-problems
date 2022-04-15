/*
    Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

    Example 1:
      Input: n = 00000000000000000000000000001011
      Output: 3
      Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
    
    Example 2:
      Input: n = 00000000000000000000000010000000
      Output: 1
      Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
*/

int hammingWeight(uint32_t n) {
    int count = 0;

    while(n > 0) {
        if(n % 2 == 1)
            count++;
        n /= 2;
    }

    return count;
}

// Time Complexity = Linear; He simply mod the input by 2, if the remainder is 1, that means we have a 1 (increment the count), else we have a 0.
