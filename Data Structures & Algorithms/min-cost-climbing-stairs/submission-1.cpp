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
        vector<int> dp(n , -1);
        return min(sol(n-1 , cost, dp), sol(n-2 , cost, dp));
    }
};
