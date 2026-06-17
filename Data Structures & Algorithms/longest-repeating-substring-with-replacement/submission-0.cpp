class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0 ; int curr =0 ;int l =0;

        vector<int>freq(26,0);

        for(int r=0;r<n;r++){

        freq[s[r]-'A']++;
        curr = max(curr , freq[s[r]-'A']);

        while(r-l+1 - curr > k){
            freq[s[l]-'A']--;
            l++;
        }
            ans = max(ans , r-l+1);
        }
        return ans;
    }
};




