class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx , vector<int>& curr , vector<int>& nums ){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        solve(idx+1 , curr , nums);
        curr.pop_back();
        solve(idx+1 , curr , nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> curr;
       solve(0,curr,nums);
       return ans; 
    }
};
