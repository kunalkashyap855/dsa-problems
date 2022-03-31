/*
    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Note that you must do this in-place without making a copy of the array.

    Example 1:
      Input: nums = [0,1,0,3,12]
      Output: [1,3,12,0,0]
    
    Example 2:
      Input: nums = [0]
      Output: [0]
*/

void moveZeroes(vector<int>& nums) {
    if(nums.size() == 1)
        return;

    int zeroCount = 0;
    int i = 0;
    while(i < nums.size()) {
        if(nums[i] == 0) {
            nums.erase(nums.begin() + i);
            zeroCount++;
        } else i++;
    }

    for(int k = 0; k < zeroCount; k++)
        nums.push_back(0);
}

// Time Complexity = O(n); First we count the total number of zeros and remove them from the array, and then we simply add the same number of 
// zeros at the end of the array.
