class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       int n = nums.size();
       unordered_set<int> list;
       for(auto num : nums){
        list.insert(num);
       } 
       if (n == list.size()){
        return false;
       }
       return true;
    }
};