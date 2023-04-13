"""
    You are given a string word that consists of digits and lowercase English letters.

    You will replace every non-digit character with a space. For example, "a123bc34d8ef34" will become " 123  34 8  34". 
    Notice that you are left with some integers that are separated by at least one space: "123", "34", "8", and "34".

    Return the number of different integers after performing the replacement operations on word.

    Two integers are considered different if their decimal representations without any leading zeros are different.

    Example 1:
      Input: word = "a123bc34d8ef34"
      Output: 3
      Explanation: The three different integers are "123", "34", and "8". Notice that "34" is only counted once.
"""

def numDifferentIntegers(self, word: str) -> int:
  word_with_space = ""

  for c in word:
      if c.isalpha():
          word_with_space += " "
      else:
          word_with_space += c

  nums = word_with_space.split(" ")

  only_nums = []
  for num in nums:
      if num != '':
          only_nums.append(int(num))

  return len(set(only_nums))

// Time Complexity = O(n)
