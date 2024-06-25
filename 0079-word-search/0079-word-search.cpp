class Solution {
private:
    bool dfs(int r, int c, int ind, vector<vector<char>>& board, string& word) {
        if (ind == word.length()) return true;
        
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[ind]) {
            return false;
        }
        
        char original = board[r][c];
        board[r][c] = '#';  // Mark as visited
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto& dir : directions) {
            int nrow = r + dir.first;
            int ncol = c + dir.second;
            if (dfs(nrow, ncol, ind + 1, board, word)) {
                board[r][c] = original;  // Restore the original character
                return true;
            }
        }
        
        board[r][c] = original;  // Restore the original character
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};