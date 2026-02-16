class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0)
            return 1;

        if (visited[i][j])
            return 0;

        visited[i][j] = true;

        return dfs(grid, i, j-1, visited) +
               dfs(grid, i, j+1, visited) +
               dfs(grid, i-1, j, visited) +
               dfs(grid, i+1, j, visited);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j, visited);
                }
            }
        }
        return 0;
    }
};
