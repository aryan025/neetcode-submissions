class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void targetSum(vector<int>& nums, int target , int ind){
        if(target == 0){
            result.push_back(path);
            return;
        }
        if(ind == nums.size() || target < 0){
            return;
        }

        //take
        target -= nums[ind];
        path.push_back(nums[ind]);
        targetSum(nums , target , ind);

        //remove the taken element
        target += nums[ind];
        path.pop_back();
        targetSum(nums , target , ind + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        targetSum(nums , target , 0);
        return result;
    }
};
