class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> st;

        for(int i=0;i<n;i++){
           
           if(st.count(nums[i]) && abs(st[nums[i]]-i) <= k ){
            return true;
           }

           st[nums[i]] = i;
        }
        return false;
    }
};