class Solution {
public:
    int m , n ;
    vector<vector<int>> dir = {
        {0,1} , {1,0}, {0,-1},{-1,0}
    };
    int dfs(int i , int j , vector<vector<bool>>& visited ,vector<vector<int>>& grid){

    if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0 ) return 0;

    visited[i][j] = true;

    int count = 1;
    for(auto &d : dir){
        int nx = d[0] + i;
        int ny = d[1] + j;
        count += dfs(nx, ny , visited , grid);
    }
    return count;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m , vector<bool>(n,false));

        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    ans = max(ans , dfs(i,j,visited,grid));
                }
            }
        }
        return ans ;
    }
};
