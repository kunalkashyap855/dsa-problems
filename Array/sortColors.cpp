/*
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
    with the colors in the order red, white, and blue.
    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

    You must solve this problem without using the library's sort function.

    Example 1:
      Input: nums = [2,0,2,1,1,0]
      Output: [0,0,1,1,2,2]
    
    Example 2:
      Input: nums = [2,0,1]
      Output: [0,1,2]
*/

void sortColors(vector<int>& nums) {
    int len = nums.size();
    if(len == 1)
        return;

    int count0 = 0, count1 = 0, count2 = 0;

    for(int i = 0; i < len; i++) {
        if(nums[i] == 0)
            count0++;
        else if(nums[i] == 1)
            count1++;
        else count2++;
    }

    int itr = 0;
    for(itr; itr < count0; itr++)
        nums[itr] = 0;

    for(itr; itr < (count0+count1); itr++)
        nums[itr] = 1;

    for(itr; itr < (count0+count1+count2); itr++)
        nums[itr] = 2;
}

// Time Complexity = O(n); Space Complexity = O(1)
