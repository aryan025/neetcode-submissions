class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size();
        int m = arr[0].size();
        // n + log(m)
        // int row = -1;
        // //find the row
        // for(int i = 0 ; i < n ; ++i){
        //     if(arr[i][m-1] < target){
        //         continue;
        //     }else{
        //         row = i;
        //         break;
        //     }
        // }

        // if(row == -1) return 0;

        // int l = 0 ; int r = m - 1;
        // while( l <= r){
        //     int mid = l + (r - l) / 2;
        //     if(arr[row][mid] == target){
        //         return 1;
        //     }else if(arr[row][mid] < target){
        //         l = mid + 1;
        //     }else{
        //         r = mid - 1;
        //     }
        // }

        //log(n * m)
        int l = 0 , r = n * m - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int row = mid / m;
            int col = mid % m;

            if(arr[row][col] == target)
                return 1;
            else if(arr[row][col] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return 0;
    }
};
