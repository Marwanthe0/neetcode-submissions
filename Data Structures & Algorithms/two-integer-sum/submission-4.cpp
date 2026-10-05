class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>> m;
        for(int i = 0;i < nums.size();i++){
            m[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(auto [vl,v]:m){
            int remaining = target - vl;
            if(vl != remaining && (m.find(remaining) != m.end())){
                ans.push_back(m[vl][0]);
                ans.push_back(m[remaining][0]);
                sort(ans.begin(),ans.end());
                return ans;
            }
            else if(vl == remaining && m[vl].size() > 1){
                ans.push_back(m[vl][0]);
                ans.push_back(m[vl][1]);
                sort(ans.begin(),ans.end());
                return ans;
            }
        }
    }
};
