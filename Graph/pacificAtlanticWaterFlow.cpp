/*
    There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and 
    the Atlantic Ocean touches the island's right and bottom edges.

    The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea 
    level of the cell at coordinate (r, c).

    The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height
    is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

    Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the 
    Pacific and Atlantic oceans.
    
    **NEED TO SEE IMAGE TO UNDERSTAND QUESTION
*/

void dfs(vector<vector<int>>& heights, int r, int c, set<pair<int, int>> &visit, int prevHeight, int rows, int cols) {
    if(visit.count(make_pair(r, c)) || r < 0 || c < 0 || r == rows || c == cols or heights[r][c] < prevHeight)
        return;

    visit.insert(make_pair(r, c));

    dfs(heights, r+1, c, visit, heights[r][c], rows, cols);
    dfs(heights, r, c+1, visit, heights[r][c], rows, cols);
    dfs(heights, r-1, c, visit, heights[r][c], rows, cols);
    dfs(heights, r, c-1, visit, heights[r][c], rows, cols);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int rows = heights.size(), cols = heights[0].size();

    set<pair<int, int>> pac, atl;

    for(int c = 0; c < cols; c++) {
        dfs(heights, 0, c, pac, heights[0][c], rows, cols);
        dfs(heights, rows-1, c, atl, heights[rows-1][c], rows, cols);
    }

    for(int r = 0; r < rows; r++) {
        dfs(heights, r, 0, pac, heights[r][0], rows, cols);
        dfs(heights, r, cols-1, atl, heights[r][cols-1], rows, cols);
    }

    vector<vector<int>> ans;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(pac.count(make_pair(i, j)) == 1 && atl.count(make_pair(i, j)) == 1) {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                ans.push_back(temp);
            }
        }
    }

    return ans;
}

/*
    For an efficient approach, we can create two sets which will include all the coordinates (r,c) that can be reached from the Pacific and Atlantic 
    oceans respectively, then we simply take the complement or the common coordinates in both sets and return them in an array. Now to do this, for Pacific Ocean,
    we start from the first row and leftmost column and from each coordinate in these we find all the coordinates that are reachable through dfs. Similarly for
    Atlantic Ocean, we will start from the rightmost column and the last row. When we go to a new coordinate, we check fi it is already in any set, and if its
    within bounds and that its height should be greater than or equal to the height of the previous coordinate (we do greater and not smaller because we are going
    opposite direction -> ocean to land). If all these checks are all right, we add the coordinate to the set and check its 4 neighbours.
*/
