class Solution {
public:
    bool solve(int l , int r , string& s){
        while(l < r){
        if(s[l] != s[r]){
            return false;
        }
            l++;
            r--;
        
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n= s.size();
        int l = 0 , r = n-1;

        while(l <= r){
            if(s[l] != s[r]){
                return solve(l+1,r,s) || solve(l , r-1, s);
            }
                l++;
                r--;
            
        }
        return true;
    }
    
};