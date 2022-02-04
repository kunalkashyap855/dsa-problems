/*
    You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.
    Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.
    
    Example 1:
      Input: n = 12, k = 3
      Output: 3
      Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
*/

int kthFactor(int n, int k) {
    vector<int> factors;
    int numFact = 0;

    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            factors.push_back(i);
            numFact++;
        }
    }

    if(k > numFact)
        return -1;

    return factors[k-1];
}

// Time Complexity = O(n)
