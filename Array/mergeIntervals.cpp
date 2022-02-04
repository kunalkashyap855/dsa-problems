/*
    Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
    and return an array of the non-overlapping intervals that cover all the intervals in the input.

    Example 1:
      Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
      Output: [[1,6],[8,10],[15,18]]
      Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/

// sort the intervals according to the start index of each interval
static bool compar(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), compar);

    vector<vector<int>> ans;
    ans.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++) {
        int lastEnd = ans.back()[1];

        if(intervals[i][0] <= lastEnd) {
            ans.back()[1] = max(lastEnd, intervals[i][1]);
        } else {
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

// Time Complexity = O(nlogn) <= because of sorting.
