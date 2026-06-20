/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;

        vector<int> start, end;

        for(auto &it : intervals){
            start.push_back(it.start);
            end.push_back(it.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0;
        int rooms = 0;
        int ans = 0;

        while(i < n){
            if(start[i] < end[j]){
                rooms++;
                ans = max(ans, rooms);
                i++;
            }else{
                rooms--;
                j++;
            }
        }

        return ans;
    }
};