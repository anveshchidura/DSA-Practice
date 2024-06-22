class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize res to the first element to handle all-negative arrays
        int res = nums[0];
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            res = max(res, sum);
        }

        return res;
    }
};
