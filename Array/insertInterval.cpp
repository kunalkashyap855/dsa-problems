/*
    You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval 
    and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end 
    of another interval.

    Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any 
    overlapping intervals (merge overlapping intervals if necessary).
    
    Example 1:
      Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
      Output: [[1,5],[6,9]]

    Example 2:
      Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
      Output: [[1,2],[3,10],[12,16]]
      Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

static bool comp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++) {
        int lastEnd = ans.back()[1];

        if(intervals[i][0] <= lastEnd)
            ans.back()[1] = max(lastEnd, intervals[i][1]);
        else ans.push_back(intervals[i]);
    }

    return ans;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);

    if(intervals.size() == 1) {
        return intervals;
    }

    sort(intervals.begin(), intervals.end(), comp);

    return mergeIntervals(intervals);
}

// Time Complexity = O(nlogn)
