class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l = 0 ; 
        int r = arr.size() - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(arr[m] == target){
                return m;
            }
            // left sorted
            if(arr[l] <= arr[m]){ 
                if(arr[l] <= target && arr[m] > target){
                        r = m - 1;
                }else{
                    l = m + 1;
                }
            }else{
                //right sorted
                if(arr[m] < target && arr[r] >= target){
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};
