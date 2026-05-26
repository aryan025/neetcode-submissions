class Solution {
public:
    int sol(vector<int> &nums, int start, int end){
        if(start > end) return 0;
        if(start == end)
            return nums[start];

        int prev2 = nums[start];
        int prev1 = max(nums[start] , nums[start + 1]);

        for(int i = start + 2 ; i <= end ; ++i){
            int curr = max(prev1, nums[i] + prev2);    //max(notTake, take);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int c1 = sol(nums, 0, n - 2);
        int c2 = sol(nums, 1, n - 1);

        return max(c1, c2);
    }
};
