class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(),mx = 1,mn = 1,ans = nums[0];
        for(int i = 0;i < n;i++){
            int tmp = mx;
            mx = max({nums[i],mx*nums[i],mn*nums[i]});
            mn = min({nums[i],mn*nums[i],tmp*nums[i]});
            ans = max(ans,mx);
        }
        return ans;
    }
};
