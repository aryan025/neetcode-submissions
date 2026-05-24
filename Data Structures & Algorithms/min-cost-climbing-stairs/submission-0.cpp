class Solution {
public:
    int sol(int ind, vector<int> &cost , int n, vector<int> &dp){
        if(ind >= n){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];

        return dp[ind] = cost[ind] + min(sol(ind + 1, cost, n, dp), sol(ind + 2 , cost, n, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n , -1);
        return min(sol(0, cost , n, dp),sol(1, cost, n, dp));
    }
};
