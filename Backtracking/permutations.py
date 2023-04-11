"""
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    Example 1:
      Input: nums = [1,2,3]
      Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    
    Example 2:
      Input: nums = [0,1]
      Output: [[0,1],[1,0]]

"""

def permute(nums: List[int]) -> List[List[int]]:
    def backtrack(start: int, result: List[List[int]]) -> None:
        if start == len(nums) - 1:
            result.append(nums[:])
            return
        for i in range(start, len(nums)):
            nums[start], nums[i] = nums[i], nums[start]
            backtrack(start + 1, result)
            nums[start], nums[i] = nums[i], nums[start]
    
    result = []
    backtrack(0, result)
    return result

# Time Complexity = O(N!*N)
