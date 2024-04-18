class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int l=0,r=0,maxl=0;
        while(r<s.size()){
            while(mpp.find(s[r]) != mpp.end()){
                mpp.erase(s[l]);
                l++;
            }
            mpp[s[r]] = r;
            maxl = max(maxl,r-l+1);
            r++;
        }
        return maxl; 
    }
};