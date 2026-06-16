class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);

        for(int sum=2;sum<=n;sum++){
            for(int i=1;i<sum;i++){
                dp[sum] =max(dp[sum], i * max(sum-i , dp[sum-i]));
            }
        }
        return dp[n];
    }
};