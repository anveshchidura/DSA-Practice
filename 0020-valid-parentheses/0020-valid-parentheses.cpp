class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mpp = {{')','('},{'}','{'},{']','['}};
        stack<char> st;
        int r = 0;
        while(r < s.size()){
            if(mpp.find(s[r]) != mpp.end()){
                if(st.empty()) return false;
                
                if(st.top() != mpp[s[r]]) return false;
                
                st.pop();
            }
            else{
                st.push(s[r]);
            }
            r++;      
        }
        return st.empty();

    }
};