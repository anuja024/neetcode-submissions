class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int len =0;
        int left =0;

        for(int right; right< s.size(); right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            len = max(len, right-left+1);
        }
        return len;
    }
};
