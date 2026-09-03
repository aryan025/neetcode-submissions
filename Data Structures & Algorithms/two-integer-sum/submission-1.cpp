class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //O(N^2)
        // int l = 0 , r = 1;
        // while(l < nums.size() - 1){
        //     if(nums[l] + nums[r] == target)
        //         return {l,r};
        //     r++;
        //     if(r >= nums.size()){
        //         l++;
        //         r = l + 1; 
        //     }
        // }
        // return{-1,-1};

        //Optimal O(N) using hashing
        unordered_map<int,int> hm;
        for(int i = 0 ; i < nums.size() ; ++i){
            int complement = target - nums[i];
            if(hm.count(complement)){
                return {hm[complement], i};
            }
            hm[nums[i]] = i;
        }
        return{-1,-1};
    }
};
