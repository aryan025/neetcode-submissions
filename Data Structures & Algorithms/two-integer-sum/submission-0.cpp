class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0 , r = 1;
        while(l < nums.size() - 1){
            if(nums[l] + nums[r] == target)
                return {l,r};
            r++;
            if(r >= nums.size()){
                l++;
                r = l + 1; 
            }
        }
        return{-1,-1};
    }
};
