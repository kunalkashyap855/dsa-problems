/*
    Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
    There is only one repeated number in nums, return this repeated number.

    You must solve the problem without modifying the array nums and uses only constant extra space.

    Example 1:
      Input: nums = [1,3,4,2,2]
      Output: 2
*/

int findDuplicate(vector<int>& nums) {
    int slow = nums[nums[0]], fast = nums[nums[nums[0]]];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    int slow2 = nums[0];
    while(slow2 != slow) {
        slow2 = nums[slow2];
        slow = nums[slow];
    }

    return slow2;
}

// Time Complexity = O(n) and Space Complexity = O(1) <= We are using the idea of Cycle in a Linked List (Floyd's Cycle Detection)
