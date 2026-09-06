class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i = 0 ; i < n - 2 ; ++i){
            //skipping the duplicate elements if we have considered 
            //the same element as fisrt element in a loop
            //so for the duplicate elements they will be consecutive 
            //as the array is sorted at this point
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int l = i + 1;
            int r = n - 1;

            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    result.push_back({nums[i] ,nums[l] , nums[r]});
                    l++;
                    r--;
                    //remove left duplicates
                    while(l < r && nums[l] == nums[l - 1]){
                        l++;
                    }
                    //remove right duplicates
                    while(l < r && nums[r] == nums[r + 1]){
                        r--;
                    }
                }else if(sum < 0){
                    l++;
                }else if(sum > 0){
                    r--;
                }
            }
        }
        return result;
    }
};
