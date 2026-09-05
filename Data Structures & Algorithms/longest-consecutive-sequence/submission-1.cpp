class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longest = 1;
        int curr =1;
        if(nums.size()==0) return 0;

        for(int i =1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]+1) curr++;
            else if(nums[i]==nums[i-1]) continue;
            else curr =1;
            longest = max(curr, longest);
        }
        return longest;
    }
};
