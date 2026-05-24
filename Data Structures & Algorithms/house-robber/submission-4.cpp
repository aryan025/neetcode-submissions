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
        // vector<int> dp(n , -1);
        // return sol(n - 1, nums, dp);
        if(n == 1){
            return nums[0];
        }
        int prev2 = nums[0];
        int prev1 = max(nums[0] , nums[1]);

        for(int i = 2 ; i < n ; ++i){
            int notTake = max(prev2, prev1);
            int take = nums[i] + prev2;
            prev2 = prev1; 
            prev1 = max(take, notTake);
        }
        return prev1;
    }
};
