"""
    Given an array of integers nums, return the number of good pairs.
    A pair (i, j) is called good if nums[i] == nums[j] and i < j.

    Example 1:
      Input: nums = [1,2,3,1,1,3]
      Output: 4
      Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
    
    Example 2:
      Input: nums = [1,1,1,1]
      Output: 6
      Explanation: Each pair in the array are good.
"""

def numIdenticalPairs(self, nums: List[int]) -> int:
    # n(n-1)/2 <= Number of unique pairs for n objects
    mymap = {}
    for n in nums:
        if n in mymap:
            mymap[n] += 1
        else:
            mymap[n] = 1

    good_pairs = 0
    for val in mymap.values():
        if val > 1:
            good_pairs += (int)((val*(val-1))/2)

    return good_pairs
  
 # Time Complexity = O(n)
