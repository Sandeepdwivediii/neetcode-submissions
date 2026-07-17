class Solution {
public:
    vector<vector<int>> res;
    void solve(int idx , vector<int>& curr ,int target , vector<int>& nums){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(nums[i] > target) continue;
            curr.push_back(nums[i]);
            solve(i , curr , target-nums[i] , nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        solve(0,curr , target, nums);
        return res;
    }
};
