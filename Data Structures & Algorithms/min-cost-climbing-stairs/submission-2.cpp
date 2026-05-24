class Solution {
public:
    int sol(int ind, vector<int> &cost , vector<int> &dp){
        if(ind <= 1){
            return cost[ind];
        }
        if(dp[ind] != -1) return dp[ind];

        return dp[ind] = cost[ind] + min(sol(ind - 1, cost, dp), sol(ind - 2 , cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n , -1);
        // return min(sol(n-1 , cost, dp), sol(n-2 , cost, dp));
        vector<int> dp(n , -1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2 ; i < n ; i++){
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        
        return min(dp[n-2] , dp[n-1]);
    }
};
