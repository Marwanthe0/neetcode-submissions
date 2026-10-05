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
        vector<pair<int,int>> v;
        for(auto vl:intervals) v.push_back({vl.start,vl.end});
        int n = v.size();
        vector<int> dif(1000005,0);
        for(auto [x,y]:v) dif[x]++,dif[y]--;
        for(int i = 1;i < dif.size();i++) dif[i] += dif[i - 1];
        return *max_element(dif.begin(),dif.end());
    }
};
