class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int time = 0;
        int fresh = 0;

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        vector<int> nr = {-1 , 0 , 1 , 0};
        vector<int> nc = {0 , 1 , 0 , -1};

        while(!q.empty() && fresh > 0){
            time++;
            int size = q.size();
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int k = 0 ; k < 4 ; ++k){
                    int nRow = nr[k] + row;
                    int nCol = nc[k] + col;

                    if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= m)
                        continue;
                    if(grid[nRow][nCol] != 1)
                        continue;
                    q.push({nRow , nCol});
                    fresh--;
                    grid[nRow][nCol] = 2;
                }
            }
        }
        if(fresh > 0)
            return -1;

        return time;
    }
};
