/*
    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
    You may assume all four edges of the grid are all surrounded by water. 

    Example 1:

    Input: grid = [
      ["1","1","1","1","0"],
      ["1","1","0","1","0"],
      ["1","1","0","0","0"],
      ["0","0","0","0","0"]
    ]
    Output: 1
*/

void visitIsland(vector<vector<char>>& grid, int x, int y, int r, int c) {
    if(x < 0 || x >= r || y < 0 || y >= c || grid[x][y] != '1')
        return;

    // mark as visited
    grid[x][y] = '2';

    visitIsland(grid, x-1, y, r, c); //LEFT
    visitIsland(grid, x, y-1, r, c); //UP
    visitIsland(grid, x+1, y, r, c); //RIGHT
    visitIsland(grid, x, y+1, r, c); //DOWN
}

int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    if(rows == 0) return 0;

    int cols = grid[0].size();

    int ans = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == '1') {
                visitIsland(grid, i, j, rows, cols);
                ans++;
            }
        }
    }

    return ans;
}

// Time Complexity = O(n + m)
