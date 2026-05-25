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

    int solve(vector<int> &nums , int start , int last){
        // int len = last - start + 1;
        // vector<int> dp(len , 0);
        // dp[0] = nums[start];
        // if(len == 1) return dp[0];

        // dp[1] = max(nums[start] , nums[start + 1]);
        // for(int i = 2 ; i < len ; ++i){
        //     int notTake = dp[i - 1];
        //     int take = nums[start + i] + dp[i - 2];

        //     dp[i] = max(take, notTake);
        // }
        // return dp[len - 1];

        if(start == last) return nums[start];

        int prev2 = nums[start];
        int prev1 = max(nums[start] , nums[start + 1]);

        for(int i = start + 2 ; i <= last ; ++i){
            int curr = max(prev1 , nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        // vector<int> dp1(n , -1);
        // vector<int> dp2(n , -1);
        // //inc last index
        // int c1 = sol(1 , n - 1 , nums, dp1);
        // int c2 = sol(0 , n - 2 , nums, dp2);
        // return max(c1, c2);

        //case1
        int c1 = solve(nums , 0 , n - 2);
        int c2 = solve(nums , 1 , n - 1);

        return max(c1 , c2);
    }
};
