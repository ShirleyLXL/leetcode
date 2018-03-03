class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i, j, a[100][100] = {0}, row = obstacleGrid.size(), col = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==0) a[0][0] = 1;
        for(i=1; i<row; i++){
            if(obstacleGrid[i][0]==0 && a[i-1][0]==1) a[i][0] = 1;
        }
        for(j=1; j<col; j++){
            if(obstacleGrid[0][j]==0 && a[0][j-1]==1) a[0][j] = 1;
        }
        for(i=1; i<row; i++){
            for(j=1; j<col; j++){
                if(obstacleGrid[i][j]==0)   a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        return a[row-1][col-1];
    }
};
