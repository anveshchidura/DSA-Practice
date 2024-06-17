#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        // figure out the grid size
        int n = grid.size();
        int m = grid[0].size();

        // store {{row, column}, time}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntFresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if cell contains rotten orange
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    // mark as visited (rotten) in visited array
                    vis[i][j] = 2;
                }
                // count fresh oranges
                if (grid[i][j] == 1) cntFresh++;
            }
        }

        int tm = 0;
        vector<vector<int>> moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int cnt = 0;

        // BFS traversal (until the queue becomes empty)
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            // check all 4 possible movements using the moves vector
            for (const auto& move : moves) {
                int nrow = r + move[0];
                int ncol = c + move[1];
                // check for valid cell and then for unvisited fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    // push in queue with timer increased
                    q.push({{nrow, ncol}, t + 1});
                    // mark as rotten
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        // if all oranges are not rotten
        if (cnt != cntFresh) return -1;

        return tm;
    }
};
