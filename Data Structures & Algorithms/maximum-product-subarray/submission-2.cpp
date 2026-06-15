class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1);

        dp[0] = 0;

        int ans = nums[0];
        int pmax = nums[0];
        int pmin = nums[0];

        for(int i = 1;i<n;i++){
           int  currmax = max({nums[i] , nums[i]* pmax , nums[i] * pmin});
           int  currmin = min({nums[i] , nums[i]* pmax , nums[i] * pmin});

            ans = max(ans,currmax);
            pmax = currmax;
            pmin = currmin;
        }
        return ans;
    }

};
