class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int minval=nums[0];
        for(int num : nums){
            if(num < minval){
                minval = num;
            }
        }
        return minval;
    }
};
