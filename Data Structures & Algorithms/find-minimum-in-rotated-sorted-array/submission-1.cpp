class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0 ; 
        int r = nums.size() - 1;
        int result = INT_MAX;
        while(l < r){
            int m = l + (r - l) / 2;
            //left sorted
            //min on right
            if(nums[m] > nums[r]){
                l = m + 1;
            }else{
                r = m;
            }
        }
        return nums[l];
    }
};
