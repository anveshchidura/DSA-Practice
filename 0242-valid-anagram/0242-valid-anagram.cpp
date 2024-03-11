class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> ans;
        if (t.length()>s.length()) swap(s,t);
        for(auto it : s){
            ans[it]++;
        }
        for(auto it : t){
            ans[it]--;
        }

        for (auto it = ans.begin(); it != ans.end(); ++it) {
            if(it->second > 0) return false;
        }
        return true;
        
    }
};