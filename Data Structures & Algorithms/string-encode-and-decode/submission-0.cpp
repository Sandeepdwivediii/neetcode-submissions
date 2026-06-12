class Solution {
public:

    string encode(vector<string>& strs) {
        string s;

        for(int i=0; i<strs.size(); i++) {
            s += strs[i];
            s += '/';
        }
        return s;

    }

    vector<string> decode(string s) {
        vector<string> ans;
        string x;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '/') { ans.push_back(x); x.clear(); i++;} 
            x += s[i];
        }
        return ans;
    }
};
// neet / code / love / you /
