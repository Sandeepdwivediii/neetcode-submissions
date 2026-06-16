class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1 , INT_MAX);

        dp[0] = 0;

        for(int sum=1;sum<=n;sum++){
            for(int i=1 ; i*i <= sum ; i++){
                int sq = i*i;
                dp[sum] = min(dp[sum] , 1+dp[sum-sq]);
            }
        }
        return dp[n];
    }
};