class Solution {
public:
    
    int dfs(vector<vector<int>>& grid , vector<vector<int>>& visited , int i , int j){
        int row = grid.size();
        int col = grid[0].size(); 
        int maxArea = 0;
        if(i < 0 || i >= row || j < 0 || j >=col){
            return 0;
        }
        if(grid[i][j] == 0 || visited[i][j]){
            return 0;
        }
        //dfs
        maxArea++;
        visited[i][j] = 1;
        vector<int>nr ={-1 , 0 , 1 , 0} ;
        vector<int>nc ={0 , 1 , 0 , -1} ;
        for(int k = 0 ; k < 4 ; ++k){
            int newR = i + nr[k];
            int newC = j + nc[k];
            maxArea += dfs(grid , visited , newR , newC);
        }
        return maxArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;

        vector<vector<int>> visited(n , vector<int>  (m , 0));

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(!visited[i][j] && grid[i][j] == 1){
                    int tempMax = dfs(grid , visited , i , j);
                    maxArea = max(maxArea , tempMax);
                }
            }
        }
        return maxArea;
    }
};
