class Solution {
public:
    vector<vector<int>> dp;
    int INF = 1e9;
    int solve(int i,vector<int>& coins , int target){
        if(target < 0) return INF;
        if(target == 0) return 0;
        if(i >= coins.size()) return INF;

        if(dp[i][target] != -1) return dp[i][target];

        

        int take = INF;
        if(coins[i] <= target) {
            take = 1 + solve(i, coins, target - coins[i]);
        }
        int skip = solve(i+1 , coins , target);

        return dp[i][target] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n, vector<int>(amount + 1, -1));

          int ans =  solve(0,coins , amount);

        if(ans >= INF) return -1;
        return ans;
    }
};
