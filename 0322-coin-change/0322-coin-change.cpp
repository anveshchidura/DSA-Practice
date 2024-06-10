class Solution {
public:
       
    int coinChange(vector<int>& coins, int amount) {
        int n =  coins.size();
        vector<int> arr = coins;
        int T = amount;
        vector<vector<int>> dp(n, vector<int>(T + 1, 0));
        for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9; // Set it to a very large value if not possible
       }
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= T; target++) {
            
            int notTake = dp[ind - 1][target];
            
            
            int take = 1e9; 
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];
                
          
            dp[ind][target] = min(notTake, take);
        }
    }
    

    int ans = dp[n - 1][T];
    
    if (ans >= 1e9)
        return -1;
    
    return ans;
    }
};