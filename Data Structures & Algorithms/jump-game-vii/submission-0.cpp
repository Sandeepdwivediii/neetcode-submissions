class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> ways(n,0);

        int count = 0;
        ways[0] = 1;

        for(int j=1;j<=n-1;j++){
            if(j - minJump >= 0){
                count += ways[j-minJump];
            }
            if(j- maxJump - 1 >= 0){
                count -= ways[j-maxJump-1];
            }
            if(count > 0 && s[j] == '0'){
                ways[j] = 1;
            }
        }
        return ways[n-1];
    }
};