class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int l = 0 ;
        int r = n - 1;
        int maxWater = INT_MIN;
        while(l < r){
            int minHeight = min(arr[l] , arr[r]);
            maxWater = max(maxWater, (minHeight * (r - l)));
            if(arr[l] < arr[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxWater;
    }
};
