class Solution {
public:
    string minWindow(string s, string t) {
        int s1 = s.size();
        int s2 = t.size();

        unordered_map<char,int> need;
        for(int i : t){
            need[i]++;
        }
        int req = need.size();

        unordered_map<char,int> window;
        int l = 0 ; int formed = 0 ; int start = 0 ; int ans = INT_MAX;

        for(int r=0;r<s1;r++){
            window[s[r]]++;

            if(need.count(s[r]) && window[s[r]] == need[s[r]]){
                formed++;
            }

            while(formed == req){
                if(r - l + 1 < ans){
                ans = min(ans , r-l+1);
                start = l;
            }

            window[s[l]]--;
            

            if(need.count(s[l]) && window[s[l]] < need[s[l]]){
                formed--;
            }
            
            l++;
        }

        }
        return (ans == INT_MAX) ? "" : s.substr(start,ans);
    }
};
