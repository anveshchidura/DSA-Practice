class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN; // maximum sum
        int sum = 0;
        for (int num : nums) {
            sum += num;
            if (sum > maxi) {
                maxi = sum;
            }
            // If sum < 0: discard the sum calculated
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};