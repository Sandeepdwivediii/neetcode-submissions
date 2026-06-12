class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string , vector<string>> mp;
        vector<vector<string>> res;
        for(int i = 0 ; i < n ; i++){
            string word = strs[i];
            string sorted_word = word;
            sort(sorted_word.begin() , sorted_word.end());
            mp[sorted_word].push_back(word);
        }
        for(auto s : mp){
            res.push_back(s.second);
        }
        return res;
    }
};
