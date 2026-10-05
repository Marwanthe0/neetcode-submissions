class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 1,ans = 1;
        if(nums.empty())ans = 0;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == nums[i - 1]) continue;
            if(nums[i] - nums[i - 1] == 1){
                count++;
                ans = max(ans,count);
            }
            else count = 1;
        }
        return ans;
    }
};
