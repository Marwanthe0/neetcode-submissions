class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> v;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i < n;i++){
            int target = (-1)*nums[i];
            int l = i + 1,r = n - 1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == target){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    v.insert(temp);
                    l++,r--;
                }
                else if(sum > target){
                    r--;
                }
                else l++;
            }
        }
    vector<vector<int>> ans;
    for(auto vl:v) ans.push_back(vl);
    return ans;
    }
};
