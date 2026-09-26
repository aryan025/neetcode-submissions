class Solution {
public:
    void dfs(vector<vector<char>>& grid , vector<vector<int>>& visited , int i , int j){
        int row = grid.size();
        int col = grid[0].size();

        if(i < 0 || i >= row || j < 0 || j >= col)
            return;
        if(grid[i][j] == '0' || visited[i][j])
            return;
            
        visited[i][j] = 1;
        vector<int> nr = {-1 , 0 , 1 , 0};
        vector<int> nc = {0 , 1 , 0 , -1};

        for(int k = 0 ; k < 4 ; ++k){
            int newR = i + nr[k];
            int newC = j + nc[k];
            dfs(grid , visited , newR , newC);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int result = 0;
        vector<vector<int>> visited(row , vector<int>(col , 0));
        for(int i = 0 ; i < row ; ++i){
            for(int j = 0 ; j < col ; ++j){
                if(grid[i][j] == '1' && !visited[i][j]){
                    result++;
                    dfs(grid , visited , i , j);
                }
            }
        }
        return result;
    }
};
