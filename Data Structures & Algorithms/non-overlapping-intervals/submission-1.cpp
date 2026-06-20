class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int count =0;

        int prev_start = intervals[0][0];
        int prev_end   = intervals[0][1];

        for(int i=1;i<n;i++){
            int curr_start = intervals[i][0];
            int curr_end   = intervals[i][1];

            if(prev_end > curr_start){
                count++;
                prev_end = min(prev_end, curr_end);
            }else{
                prev_start = curr_start;
                prev_end = curr_end;
            }
        }
        return count;
    }
};
