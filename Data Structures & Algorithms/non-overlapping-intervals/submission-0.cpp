class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      vector<pair<int,int>> v;
      for(auto vl:intervals){
        v.push_back({vl[0],vl[1]});
        }
      sort(v.begin(),v.end(),[&](pair<int,int> a,pair<int,int> b){return a.second < b.second;});
      int ans = 0,last = INT_MIN;
      for(auto vl:v){
        // cout<<vl.first<<" "<<vl.second<<endl;
        if(vl.first >= last) ans++,last = vl.second;
      }
      return v.size() - ans;
    }
};
