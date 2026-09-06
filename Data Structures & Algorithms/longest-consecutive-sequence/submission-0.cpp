class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs;
        int length = 0;
        for(auto &it:nums)
            hs.insert(it);
        
        for(int i = 0 ; i < nums.size() ; ++i){
            int prevNo = nums[i] - 1;
            if(!hs.count(prevNo)){
                int currLen = 1;
                int current = nums[i];
                while(hs.count(current + 1)){
                    currLen++;
                    current += 1;
                }
                length = max(length, currLen);
            }else{
                continue;
            }
        }
        return length;
    }
};
