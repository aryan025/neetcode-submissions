class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void allSubsets(vector<int>& nums, int target , int ind){
        if(target == 0){
            result.push_back(path);
            return;
        }
        if(ind == nums.size() || target < 0){
            return;
        }
        //take
        path.push_back(nums[ind]);
        allSubsets(nums , target - nums[ind] , ind + 1);

        //pop the taken element from the path
        path.pop_back();

        //not take
        int next = ind + 1;
        while(next < nums.size() && nums[ind] == nums[next]){
            next++;
        }
        allSubsets(nums , target , next);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        allSubsets(nums , target , 0);
        return result; 
    }
};
