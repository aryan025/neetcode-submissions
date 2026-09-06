class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0 , r = numbers.size() - 1;
        while(l < r){
            int sumTemp = numbers[l] + numbers[r];
            if(sumTemp == target){
                return{l + 1 , r + 1};
            }else if(sumTemp < target){
                l++;
            }else{
                r--;
            }
        }
        return{};
    }
};
