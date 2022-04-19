/*
    Implement strStr().
    Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    What should we return when needle is an empty string? This is a great question to ask during an interview.
    For the purpose of this problem, we will return 0 when needle is an empty string. 
    
    Example 1:
      Input: haystack = "hello", needle = "ll"
      Output: 2
    
    Example 2:
      Input: haystack = "aaaaa", needle = "bba"
      Output: -1
*/

int strStr(string haystack, string needle) {
    if(needle.size() == 0)
        return 0;

    int h = 0, n = 0;
    int ans = -1;

    while(h < haystack.size() && n < needle.size()) {
        if(haystack[h] == needle[n]) {
            h++;
            n++;
            if(n == 1)
                ans = h-1;
        } else if (ans != -1) {
            h = ans + 1;
            n = 0;
            ans = -1;
        } else h++;
    }

    if(n == needle.size())
        return ans;

    else return -1;
}

// Time Complexity = O(n) <= where 'n' is the length of haystack.
