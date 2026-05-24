class Solution {
public:
    int sol(int ind , vector<int> &nums, vector<int> &dp){
        if(ind < 0){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int notTake = sol(ind - 1 , nums, dp);
        int take = INT_MIN;
        if(ind >= 0){
            take = nums[ind] + sol(ind - 2, nums, dp);
        }
        return dp[ind] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        return sol(n - 1, nums, dp);
    }
};
