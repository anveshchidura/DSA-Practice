class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int,int> mpp;
        for(int i = 0;i< nums.size();i++){
            mpp[nums[i]] = 0;
        }
        for(int i = 0;i< nums.size();i++){
            mpp[nums[i]]++;
        }
        for(int i = 0;i< nums.size();i++){
            if(mpp[nums[i]] > 1) return true;
            
        }
        return false;
        
        
        
    }
};