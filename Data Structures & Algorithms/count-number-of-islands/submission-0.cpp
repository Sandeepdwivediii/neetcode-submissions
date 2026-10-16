class Solution {
public:
    int m,n;
    vector<vector<int>> dir = {
        {0,1} , {0,-1} , {1,0} ,{-1,0}
    };
    void dfs(vector<vector<char>>& grid , int i , int j , vector<vector<bool>>& visited){

        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] == '0') return;

        visited[i][j] = true;

        for(auto &d : dir){
            int nx = d[0] + i;
            int ny = d[1] + j;

            dfs(grid,nx,ny,visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid , i , j , visited);
                    count++;
                }
            }
        }
        return count;
    }
};
