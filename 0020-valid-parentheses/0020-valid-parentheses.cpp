class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mpp = {{')','('},{'}','{'},{']','['}};
        stack<char> st;
        int r = 0;
        while(r < s.size()){
            if(mpp.find(s[r]) != mpp.end()){
                if(st.empty()) return false;
                char stop = st.top();
                st.pop();
                if(stop != mpp[s[r]]) return false;
            }
            else{
                st.push(s[r]);
            }
            r++;      
        }
        if(st.empty()) return true;
        return false;
    }
};