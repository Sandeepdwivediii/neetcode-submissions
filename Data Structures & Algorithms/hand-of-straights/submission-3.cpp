class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;

        map<int,int> mp;
        for(auto &el:hand){
            mp[el]++;
        }
        for(auto [card , count] : mp){
            if(count > 0){
                for(int i=1;i<groupSize;i++){
                    if(mp[card+i] < count) return false;
                    mp[card+i] -= count;
                }
            }
        }
        return true;
        }
    
};
