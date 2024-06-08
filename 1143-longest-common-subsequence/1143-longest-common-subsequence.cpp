class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        // Create a 2D dp array initialized with 0s
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Fill the dp table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The answer is in dp[n][m]
        return dp[n][m];
    }
};

/*
class Solution {
public:
    
    int strmatch(int i,int j,string &text1, string &text2,vector<vector<int>> &dp)    {
        if(i<0||j<0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        if(text1[i] == text2[j]) return 1 + strmatch(i-1,j-1,text1,text2,dp);
        
        return dp[i][j] = max(strmatch(i,j-1,text1,text2,dp),strmatch(i-1,j,text1,text2,dp));
          
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return strmatch(n-1,m-1,text1,text2,dp);
        

    }
};

*/