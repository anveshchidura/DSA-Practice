class Solution {
public:
bool isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, int> count;

    for (int i = 0; i < s.length(); ++i) {
        count[s[i]]++;
        count[t[i]]--;
    }

    for (const auto& pair : count) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}
};