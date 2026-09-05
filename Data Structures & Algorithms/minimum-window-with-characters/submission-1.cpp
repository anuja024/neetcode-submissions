class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()> s.size()){
            return "";
        }

        unordered_map<char, int> need, window;

        int left =0;
        int minlen = INT_MAX;
        int start =0;
        
        int have = 0;

        for( char c : t){
            need[c]++;
        }
        int needcount= need.size();

        for(int right = 0; right< s.size(); right ++){
            char c = s[right];
            window[c]++;

            if( need.count(c) && window[c]== need[c]){
                have ++;
            }
            while(have == needcount){
                if(right - left +1 < minlen){
                    minlen = right - left +1;
                    start = left;
                }
                window[s[left]]--;

                if(need.count(s[left]) && window[s[left]] < need[s[left]]){
                    have --;
                }
                left ++;
            }
        }
        if (minlen == INT_MAX) return "";

        return s.substr(start, minlen);
    }
};
