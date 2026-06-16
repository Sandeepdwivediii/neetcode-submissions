class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int idx , int buy , vector<int>& prices){
        if(idx >= n) return 0;

        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }

        if(buy == 1){
            int take = -prices[idx] + solve(idx+1 , 0 , prices);
            int skip = solve(idx+1 , 1 , prices);
            return dp[idx][buy] = max(take,skip);
        }else if(buy == 0){
            int sell = prices[idx] + solve(idx+2,1,prices);
            int skip = solve(idx+1 , 0 , prices);
            return dp[idx][buy] = max(sell,skip);
        }

        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        n  = prices.size();
        dp.assign(n,vector<int>(2,-1));
        return solve(0,1,prices);
    }
};
