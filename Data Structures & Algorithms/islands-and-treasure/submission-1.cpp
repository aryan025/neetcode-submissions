class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n , vector<int>(m , 0));
        queue<pair<int,int>> q;
        
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] == 0)
                    q.push({i,j});
            }
        }
        vector<int> nr = {-1, 0, 1, 0};
        vector<int> nc = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; ++i){
                int newR = row + nr[i];
                int newC = col + nc[i];

                if(newR < 0 || newR >= n || newC < 0 || newC >= m){
                    continue;
                }
                if(grid[newR][newC] != INT_MAX)
                    continue;
                grid[newR][newC] = grid[row][col] + 1; 
                q.push({newR , newC});
            }
        }
    }
};
