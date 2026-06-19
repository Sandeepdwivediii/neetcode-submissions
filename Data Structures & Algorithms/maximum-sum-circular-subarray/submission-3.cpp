class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> mindp(n) ; vector<int> maxdp(n);

        int maxsum = nums[0];
        int minsum = nums[0];
        mindp[0] = nums[0];
        maxdp[0] = nums[0];
        int total = nums[0];

        for(int i=1;i<n;i++){
            maxdp[i] = max(nums[i] , nums[i]+ maxdp[i-1]);
            mindp[i] = min(nums[i] , nums[i]+ mindp[i-1]);

            maxsum = max(maxsum , maxdp[i]);
            minsum = min(minsum , mindp[i]);

            total += nums[i];
        }
        if(maxsum < 0) return maxsum;
        return max({maxsum , total-minsum});
    }
};