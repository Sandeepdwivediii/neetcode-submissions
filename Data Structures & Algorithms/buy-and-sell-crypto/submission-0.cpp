class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mini = INT_MAX , ans =0;
        for(int price : prices){
            mini = min(mini , price );
            ans = max(ans , price - mini);
        }
        return ans;
    }
};
