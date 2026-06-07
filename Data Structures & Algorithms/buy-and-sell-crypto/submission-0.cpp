class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int minPrice = INT_MAX;
        for(auto it : prices){
            minPrice = min(minPrice, it);
            maxProfit = max(maxProfit, it - minPrice);
        }
        return maxProfit;
    }
};
