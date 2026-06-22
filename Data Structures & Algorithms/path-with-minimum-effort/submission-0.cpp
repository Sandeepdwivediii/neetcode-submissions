class Solution {
public:
    vector<vector<int>> dir = {
        {0,1} , {1,0} , {-1,0} , {0,-1}
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
      int m = heights.size();
      int n = heights[0].size();

      vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
      dist[0][0] = 0;

      priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<>> pq;
      pq.push({0,0,0});

      while(!pq.empty()){
        auto [effort ,x,y] = pq.top();
        pq.pop();

        if(x == m-1 && y == n-1){
            return effort;
        }

        for(auto &d : dir){
            int nx = d[0]+x;
            int ny = d[1]+y;

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            int new_eff = abs(heights[x][y] - heights[nx][ny]);
            new_eff = max(effort , new_eff);

            if(new_eff < dist[nx][ny]){
                dist[nx][ny] = new_eff;
                pq.push({new_eff , nx,ny});
            }
        }
      }
      return 0;
    }
};

// we need a queue - row , col , effort;
// we need to find the shortest distance in terms of effort ; 
// effort = abs(height[x][y] - heights[nx][ny]);
// if new_effort < dist[nx][ny] update it 