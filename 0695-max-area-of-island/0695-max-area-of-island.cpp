/*
    Given grid where '1' is land & '0' is water, return largest island

    DFS, set visited land to '0' to not visit it again, store biggest

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, m, n,area);
                    result = max(result, area);
                    
                }
            }
        }
        
        return result;
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int& area) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        area++;
        dfs(grid, i - 1, j, m, n,area); 
        dfs(grid, i + 1, j, m, n,area);
        dfs(grid, i, j - 1, m, n,area);
        dfs(grid, i, j + 1, m, n,area);
    }
};
