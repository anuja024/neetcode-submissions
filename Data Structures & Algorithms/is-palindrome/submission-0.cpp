class Solution {
public:
    bool isPalindrome(string s) {
        string rev = "";
        for(char c: s){
            if(isalnum(c)){
                rev += tolower(c);
            }
        }
        string str= rev;
        reverse(str.begin(), str.end());
        return str == rev;
    }
};
