class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        int result = 0; // Start with 0, not INT_MIN

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 1) {
                    int area = 0; // Initialize area here
                    dfs(grid, i, j, m, n, vis, area);
                    result = max(result, area);
                }
            }
        }
        
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& vis, int& area) {
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] == 1 || grid[i][j] == 0) {
            return;
        }
        vis[i][j] = 1;
        area++;
        dfs(grid, i - 1, j, m, n, vis, area);
        dfs(grid, i + 1, j, m, n, vis, area);
        dfs(grid, i, j - 1, m, n, vis, area);
        dfs(grid, i, j + 1, m, n, vis, area);
    }
};
