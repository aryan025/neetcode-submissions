class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row , int col){
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;

        vector<int> nr = {-1 , 0 , 1 , 0};
        vector<int> nc = {0 , 1 , 0 , -1};

        for(int k = 0 ; k < 4 ; ++k){
            int newR = row + nr[k];
            int newC = col + nc[k];

            if(newR < 0 || newR >= n || newC < 0 || newC >=m)
                continue;
            if(visited[newR][newC])
                continue;
            if(grid[newR][newC] < grid[row][col])
                continue;
            dfs(grid , visited , newR , newC);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> pacific(n , vector<int>(m , 0));
        vector<vector<int>> atlantic(n , vector<int>(m , 0));
        //pacific

        //top view
        for(int i = 0 ; i < m ; ++i)
            dfs(grid , pacific , 0 , i);
        //left view
        for(int i = 0 ; i < n ; ++i)
            dfs(grid , pacific , i , 0);
        
        //atlantic

        //bottom view
        for(int i = 0 ; i < m ; ++i)
            dfs(grid , atlantic , n - 1 , i);
        //right view
        for(int i = 0 ; i < n ; ++i)
            dfs(grid , atlantic , i , m - 1);

        vector<vector<int>> result;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i , j});
                }
            }
        }
        return result;
    }
};
