class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int maxlen = 0;
        int left=0;

        for(int right=0; right< s.length(); right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            int length = right - left+1;
            maxlen = max(maxlen, length);
        }
        return maxlen;
    }
};
