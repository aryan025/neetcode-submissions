class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int result = 0;

        int lmax = 0;
        int rmax = 0;

        int l = 0 , r = n - 1;

        while(l < r){
            if(arr[l] <= arr[r]){
                if(arr[l] >= lmax){
                    lmax = arr[l];
                }else{
                    result += lmax - arr[l];
                }
                l++;
            }else{
                if(arr[r] >= rmax){
                    rmax = arr[r];
                }else{
                    result += rmax - arr[r];
                }
                r--;
            }
        }
        return result;
    }
};
