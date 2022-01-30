/*  
    Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
    If target is not found in the array, return [-1, -1].

    You must write an algorithm with O(log n) runtime complexity.
*/

int findFirst(vector<int>& nums, int target) {
    if(nums[0] == target)
        return 0;
    int start = 0, end = nums.size() - 1;

    while(start <= end) {
        int mid = (start+end)/2;
        if(nums[mid] == target && nums[mid-1] < target)
            return mid;
        else if(nums[mid] < target)
            start = mid+1;
        else end = mid-1;
    }

    return -1;
}

int findLast(vector<int>& nums, int target) {
    if(nums[nums.size()-1] == target)
        return nums.size()-1;
    int start = 0, end = nums.size() - 1;

    while(start <= end) {
        int mid = (start+end)/2;
        if(nums[mid] == target && nums[mid+1] > target)
            return mid;
        else if(nums[mid] > target)
            end = mid-1;
        else start = mid+1;
    }

    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;

    if(nums.size() == 0 || nums[0] > target || nums[nums.size()-1] < target) {
        ans.push_back(-1);
        ans.push_back(-1);
    } else {
        ans.push_back(findFirst(nums, target));
        ans.push_back(findLast(nums, target));
    }

    return ans;
}

// Time Complexity = O(logn) <- Because of Binary Search
