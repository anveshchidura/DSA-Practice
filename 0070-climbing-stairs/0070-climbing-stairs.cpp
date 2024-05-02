class Solution {
public:
    
int reach(int n, vector<int> &dp){
    if(n == 0) return 1;
    if(n < 0 ) return 0;
    if(dp[n] != 0) return dp[n]; 

    int step1 = reach(n-1, dp);
    int step2 = reach(n-2, dp);

    return dp[n] = step1 + step2;
}

int climbStairs(int n) {
    vector<int> dp(n+1, 0); // Initialize dp with size n+1 and fill with 0
    return reach(n, dp);
}
};