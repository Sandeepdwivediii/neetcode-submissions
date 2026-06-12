class Solution {
public:
    bool canship(vector<int>& weights , int capacity , int days){
        int curr_load = 0 ; int req_days = 1;

        for(int w : weights){
            if(w+curr_load > capacity){
                req_days++;
                curr_load = 0;
            }
            curr_load += w;
        }
        return req_days <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin() , weights.end());
        int high = accumulate(weights.begin(), weights.end() , 0);
        int ans = 0 ;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canship(weights , mid , days)){
                ans = mid ;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
    
    return ans ;
    }
};