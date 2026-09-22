class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& nums, int k) {
        priority_queue<pair<long long,int>> pq;

        for(int i = 0 ; i < nums.size() ; ++i){
            long long dist = 1LL * nums[i][0] * nums[i][0]
                                + 1LL * nums[i][1] * nums[i][1];
            pq.push({dist , i});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while(!pq.empty()){
            int ind = pq.top().second;
            pq.pop();
            result.push_back(nums[ind]);
        }
        return result;
    }
};
