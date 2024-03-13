class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }
        return { -1, -1};

        /*
            
        sort(nums.begin(),nums.end());
        int i = 0,j = nums.size()-1;
        while(i<j){
            if(nums[i] + nums[j] == target) return {i,j};
            if(nums[i] + nums[j] > target){
                j--;
            }
            else{
                i++;
            }
        }      
     return {};
     */
    }
};