class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;

        for(string word : strs){
            string orig = word;
            sort(orig.begin() , orig.end());
            mp[orig].push_back(word);
        }

        vector<vector<string>> ans;
        for(auto &el : mp){
            ans.push_back(el.second);
        }
        return ans;
    }
};
