class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(),idx = 0;
        pair<int,int> ni = {newInterval[0],newInterval[1]};
        while(idx < n && intervals[idx][0] <= ni.first) idx++;
        intervals.insert(intervals.begin() + idx,newInterval);
        int last = INT_MIN;
        vector<vector<int>> ans;
        for(int i = 0;i <= n;i++){
            if(intervals[i][0] <= last){
                ans.back()[1] = last = max(last,intervals[i][1]);
            }
            else{ 
                ans.push_back(intervals[i]);
                last = intervals[i][1];
                }
        }
        for(auto vl:intervals){
            for(auto val:vl) cout<<val<<" ";
            cout<<endl;}
        return ans;
    }
};
