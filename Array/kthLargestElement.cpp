/*
    Given an integer array nums and an integer k, return the kth largest element in the array.

    Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;

    for(int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
    }


    for(int i = 0; i < k-1; i++) {
        pq.pop();
    }

    return pq.top();
}

/*
    We can simply sort the array and return the (n-k)th element. Time complexity for this approach will be O(nlogn).
    
    We can improve this time complexity by using Priority Queue as done here.
    Time Complexity = O(n + klogn)
    Note that this only gives a difference when k << n. Because if k ~= n => O(n + klogn) ~= O(nlogn).
*/
