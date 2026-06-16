class Solution {
public:
    vector<vector<int>> dp;
    int m , n;
    int solve(int i , int j , vector<vector<int>>& obstacleGrid){
        if(i >= m || j >= n ) return 0;
          if(obstacleGrid[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        int down = solve( i+1 , j , obstacleGrid);
        int right = solve( i , j+1, obstacleGrid);

        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
         dp.assign(m , vector<int>(n,-1));
        return solve(0,0,obstacleGrid);
    }
    
};