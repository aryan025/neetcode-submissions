class Solution {
public:
    int hrsReq(int rate, vector<int> &arr){
        int hrsReq = 0;
        for(auto &it : arr){
            hrsReq += ceil((double)it / rate);
        }
        return hrsReq;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = INT_MIN;
        for(auto &it : piles){
            maxi = max(maxi, it);
        }

        int l = 1 , r = maxi;
        int result = 0;
        while(l <= r){
            int m = l + (r - l) / 2;
            int hrsReqValue = hrsReq(m, piles);
            if(hrsReqValue <= h){
                r = m - 1;
                result = m;
            }
            else
                l = m + 1;
        }
        return result;
    }
};
