/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
    You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    Return true if you can finish all courses. Otherwise, return false.
*/

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses, vector<int>());
    vector<int> degree(numCourses, 0);

    for (auto &p: prerequisites) {
        adj[p[1]].push_back(p[0]);
        degree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (degree[i] == 0) q.push(i);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        numCourses--;
        for (auto next: adj[curr])
            if (--degree[next] == 0) q.push(next);
    }

    return numCourses == 0;
}

/* 
    Time Complexity = O(n+m)
    
    We can simply apply the concept of Topological sort. Here first we create a list of all courses that have prerequisites. Then we create a queue and insert all
    those courses in the queue which does not have any prerequisites. Then in the while loop, we go through the queue until it gets empty, and in each iteration we
    visit one of the courses with no prereqs or no remaining prereqs, we decerement the numCourses after we visit one course and then we check the courses which
    ehich depended on the curr course, and now if their prereqs have been satisfied, those courses are added to the queue. At the end of the for loop, if numCourses
    becomes 0, that is we were able to visit each in a correct order, then we return tru, else false.
*/
