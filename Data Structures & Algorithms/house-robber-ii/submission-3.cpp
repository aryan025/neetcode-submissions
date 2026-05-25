class Solution {
public:
    int sol(int start, int last, vector<int> &nums, vector<int> &dp){
        if(start > last){
            return 0;
        }
        if(last == start)
            return nums[last];

        if(dp[last] != -1) return dp[last];
        int notTake = sol(start, last - 1, nums, dp);
        int take = nums[last] + sol(start, last - 2, nums, dp);
        
        return dp[last] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n , -1);
        vector<int> dp2(n , -1);
        //inc last index
        int c1 = sol(1 , n - 1 , nums, dp1);
        int c2 = sol(0 , n - 2 , nums, dp2);
        return max(c1, c2);
    }
};
