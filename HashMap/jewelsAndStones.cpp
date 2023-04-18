/*
    You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. 
    Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

    Letters are case sensitive, so "a" is considered a different type of stone from "A".

    Example 1:
      Input: jewels = "aA", stones = "aAAbbbb"
      Output: 3
    
    Example 2:
      Input: jewels = "z", stones = "ZZ"
      Output: 0
*/

int numJewelsInStones(string jewels, string stones) {
    unordered_map<int, bool> jewels_map;

    for(int i = 0; i < jewels.size(); i++) {
        if(!jewels_map.count(jewels[i]))
            jewels_map[jewels[i]] = true;
    }

    int ans = 0;
    for(int i = 0; i < stones.size(); i++) {
        if(jewels_map.count(stones[i]))
            ans++;
    }

    return ans;
}
  
// Time Complexity = O(n)
