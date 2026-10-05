class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(),ans = 0ll;
        long long mask = (1ll<<n);
        for(int i = 0;i < mask;i++){
            int sum = 0;
            for(int j = 0;j < n;j++){
                if(1&(i>>j)){
                    sum += nums[j];
                }
                else sum -= nums[j];
            }
            ans += (sum == target);
        }
        return ans;
    }
};
