class Solution {
public:
    vector<int> dp;
    
    int solve(int idx ,int end, vector<int>& nums){
        if(idx > end) return 0;
        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + solve(idx+2,end ,nums);
        int skip = solve(idx+1 ,end , nums);

        return dp[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
         if(n == 1) return nums[0];

         
        dp.assign(n,-1);
        int a = solve(0,n-2,nums);

        dp.assign(n,-1);
        int b = solve(1,n-1,nums);
    
        return max(a,b);
    }
};
