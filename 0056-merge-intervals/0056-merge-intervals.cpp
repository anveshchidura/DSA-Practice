class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        results.push_back({intervals[0]});
        for(int i = 1; i < n;i++){
            if(intervals[i][0] <= results.back()[1]){
                results.back()[1] = max(intervals[i][1],results.back()[1]);
            }
            else{
                results.push_back(intervals[i]);
            }
            
        }    
        return results;
        
}
};