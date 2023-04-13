"""
    You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num.
    Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.

    For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs 
    [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
    Return the minimum possible sum of new1 and new2.

    Example 1:
      Input: num = 2932
      Output: 52
      Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
      The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
    
    Example 2:
      Input: num = 4009
      Output: 13
      Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
      The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.
"""

def minimumSum(self, num: int) -> int:
    num_str = str(num)

    my_list = []
    for i in range(len(num_str)):
        my_list.append(int(num_str[i]))

    if my_list.count(0) >= 2:
        return sum(my_list)

    my_list.sort()

    ans = ((my_list[1]*10 + my_list[2]) + (my_list[0] * 10 + my_list[3]))
    return ans
  
 # Time Complexity = O(1) <= Constant time because the number is always 4 digits, so the list of digits will also always be of length 4.
