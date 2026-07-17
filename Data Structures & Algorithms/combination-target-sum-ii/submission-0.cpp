class Solution {
public:
    vector<vector<int>> res;
    void solve(int idx , vector<int>& curr ,vector<int>& candidates , int target){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            curr.push_back(candidates[i]);
            solve(i+1 , curr , candidates , target-candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int> curr;
        solve(0,curr,candidates , target);
        return res;
    }
};
