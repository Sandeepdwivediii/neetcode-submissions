class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(nums.begin() , nums.end() ,0);
        if (target%2 != 0) return false;

        int sum = target/2;

        vector<int>dp(sum+1,false);
        dp[0] = true;

        for(int i : nums){
            for(int s = sum;s>=i;s--){
                    dp[s] = dp[s] || dp[s-i];
                 
                }
            }
        
        return dp[sum];
    }
};
