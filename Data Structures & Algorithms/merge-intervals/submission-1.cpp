class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int last = INT_MIN;
        vector<pair<int,int>> v;
        for(auto vl:intervals) v.push_back({vl[0],vl[1]});
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        for(int i = 0;i < n;i++){
            if(v[i].first <= last){
                ans.back()[1] = last = max(last,v[i].second);
            }
            else{ 
                vector<int> temp;
                temp.push_back(v[i].first);
                temp.push_back(v[i].second);
                ans.push_back(temp);
                last = v[i].second;
                }
        }
        return ans;
    }
};
