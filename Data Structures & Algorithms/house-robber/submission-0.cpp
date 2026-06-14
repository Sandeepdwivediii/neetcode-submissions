class Solution {
public:
    vector<int> dp;
    int solve(int idx ,vector<int>& nums){
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];
        
        int take = nums[idx] + solve(idx-2 , nums);
        int skip = solve(idx-1,nums);

        return dp[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        return solve(nums.size()-1,nums);
    }
};
