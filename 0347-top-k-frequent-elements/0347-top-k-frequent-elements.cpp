#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<int> res;

        // Count the frequency of each element in nums
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        // Create a vector of pairs from the unordered_map
        vector<pair<int, int>> freqVec(mpp.begin(), mpp.end());

        // Sort the vector based on the frequency in descending order
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return b.second < a.second;
        });

        // Collect the top k frequent elements
        for (int i = 0; i < k; i++) {
            res.push_back(freqVec[i].first);
        }

        return res;
    }
};
