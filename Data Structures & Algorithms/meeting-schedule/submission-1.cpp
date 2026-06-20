class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0) return true;

        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            return a.start < b.start;
        });

        int prev_end = intervals[0].end;

        for(int i = 1; i < n; i++){
            int curr_start = intervals[i].start;
            int curr_end = intervals[i].end;

            if(curr_start < prev_end){
                return false;
            }

            prev_end = curr_end;
        }

        return true;
    }
};