/*
    Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make 
    the rest of the intervals non-overlapping.

    Example 1:
      Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
      Output: 1
      Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
*/

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int count = 0;

    sort(intervals.begin(), intervals.end());

    int l = 0;
    int r = 1;

    while(r < intervals.size()) {
        if(intervals[l][1] <= intervals[r][0])
            l = r++;
        else if(intervals[l][1] <= intervals[r][1]) {
            count++;
            r++;
        } else if(intervals[l][1] > intervals[r][1]) {
            count++;
            l = r++;
        }
    }

    return count;
}

// Time Complexity = O(nlogn)
