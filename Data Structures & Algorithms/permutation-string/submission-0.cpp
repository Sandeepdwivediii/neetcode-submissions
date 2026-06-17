class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int>freq(26,0);
        for(char c : s1){
            freq[c-'a']++;
        }

        vector<int> window(26,0);

        int l =0 ;
        for(int r=0;r<m;r++){
            window[s2[r]-'a']++;


            if(r-l+1 > n){
                window[s2[l]-'a']--;
                l++;
            }

             if(freq == window) return true;
             
        }
        return false;
    }
};
