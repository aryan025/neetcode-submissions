class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void subset(vector<int>& nums , int ind){
        if(ind == nums.size()){
            result.push_back(path);
            return;
        }
        //take
        path.push_back(nums[ind]);
        subset(nums , ind + 1);
        
        //not take
        path.pop_back();
        int next = ind + 1;
        while(next < nums.size() && nums[next] == nums[ind])
            next++;
        subset(nums , next);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        subset(nums, 0);
        return result;
    }
};
