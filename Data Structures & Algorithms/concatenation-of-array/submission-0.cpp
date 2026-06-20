class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> num;

        for(int i=0;i<2*n;i++){
            int k=i%n;
            num.push_back(nums[k]);
        }
        return num;
    }
};