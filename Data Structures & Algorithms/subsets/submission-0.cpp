class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;

    void allSubset(vector<int>& nums, int ind){
        //if no more options then push to result
        if(ind == nums.size()){
            result.push_back(subset);
            return;
        }
        //take
        subset.push_back(nums[ind]);
        //expore other when take is there
        allSubset(nums , ind + 1);

        //pop the current element
        subset.pop_back();
        //not take
        //the again from next do take not take
        allSubset(nums , ind + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        allSubset(nums, 0);
        return result;
    }
};
