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

const auto COMP = [](const Interval& a1, const Interval& a2){
	return a1.start < a2.start;
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), COMP);
		int prev_end = -1;
		for(auto i: intervals){
			if(i.start < prev_end)
				return false;

			prev_end = i.end;
		}
		return true;
    }	
};
