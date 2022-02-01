/*
    Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
    return the area of the largest rectangle in the histogram.
*/

vector<int> NSL(vector<int> arr, int n) {
    stack<pair<int, int> > s; vector<int> ans;

    for(int i = 0; i < n; i++){
        while(!s.empty() && s.top().first >= arr[i])
            s.pop();

        if(s.empty())
            ans.push_back(-1);
        else ans.push_back(s.top().second);

        s.push(make_pair(arr[i], i));
    }

    return ans;
}

vector<int> NSR(vector<int> arr, int n) {
    stack<pair<int, int> > s; vector<int> ans;

    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && s.top().first >= arr[i])
            s.pop();

        if(s.empty())
            ans.push_back(n);
        else ans.push_back(s.top().second);

        s.push(make_pair(arr[i], i));
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    if(heights.size() == 0)
        return 0;

    vector<int> area;
    int n = heights.size();

    vector<int> left = NSL(heights, n);
    vector<int> right = NSR(heights, n);

    for(int i = 0; i < n; i++)
        area.push_back(heights[i] * (right[i] - left[i] - 1));

    return *max_element(area.begin(), area.end());
}

// Time Complexity = O(n) <= Using the concept of Monotonic Stack
