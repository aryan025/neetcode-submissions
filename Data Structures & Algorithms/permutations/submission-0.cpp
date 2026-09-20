class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void permu(vector<int>& nums, vector<bool>& used){
        //all used = path size = nums size
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0 ; i < nums.size() ; ++i){
            if(used[i])
                continue;
            //take
            used[i] = true;
            path.push_back(nums[i]);

            permu(nums , used);

            //not take
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size() , false);
        permu(nums , used);
        return result;
    }
};
