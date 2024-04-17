#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> mpp;
        int l = 0, r = 0;
        int maxLength = 0;

        while (r < s.size()) {
            char currentChar = s[r];

            if (mpp.find(currentChar) != mpp.end() && mpp[currentChar] >= l) {
                l = mpp[currentChar] + 1;
            }

            mpp[currentChar] = r;
            int currentLength = r - l + 1;
            maxLength = std::max(maxLength, currentLength);
            r++;
        }

        return maxLength;
    }
};
