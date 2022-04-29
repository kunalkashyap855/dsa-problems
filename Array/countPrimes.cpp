/*
    Given an integer n, return the number of prime numbers that are strictly less than n.

    Example 1:
      Input: n = 10
      Output: 4
      Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
    
    Example 2:
      Input: n = 0
      Output: 0
*/

bool isPrime(int num) {
   if (num <= 1) return false;
   // Loop's ending condition is i * i <= num instead of i <= sqrt(num)
   // to avoid repeatedly calling an expensive function sqrt().
   for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) return false;
   }
   return true;
}

int countPrimes(int n) {
    if(n == 0)
        return 0;

   bool isPrime[n];
   for (int i = 2; i < n; i++) {
      isPrime[i] = true;
   }

   // Loop's ending condition is i * i < n instead of i < sqrt(n)
   // to avoid repeatedly calling an expensive function sqrt().
   for (int i = 2; i * i < n; i++) {
      if (!isPrime[i]) 
          continue;

      for (int j = i * i; j < n; j += i) {
         isPrime[j] = false;
      }
   }

   int count = 0;
   for (int i = 2; i < n; i++) {
      if (isPrime[i]) count++;
   }

   return count;
}
