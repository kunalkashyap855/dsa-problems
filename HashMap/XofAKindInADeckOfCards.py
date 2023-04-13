"""
    You are given an integer array deck where deck[i] represents the number written on the ith card.

    Partition the cards into one or more groups such that:

    Each group has exactly x cards where x > 1, and
    All the cards in one group have the same integer written on them.
    Return true if such partition is possible, or false otherwise.

    Example 1:
      Input: deck = [1,2,3,4,4,3,2,1]
      Output: true
      Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
    
    Example 2:
      Input: deck = [1,1,1,2,2,2,3,3]
      Output: false
      Explanation: No possible partition.
"""

def hasGroupsSizeX(self, deck: List[int]) -> bool:
    if len(deck) == 1:
        return False

    freq_map = Counter(deck)

    if gcd(*list(freq_map.values())) > 1:
        return True

    return False
  
# Time Complexity = O(n) 
