class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pf(n + 1,0);
        int ans = INT_MIN,mn = 0;
        for(int i = 1;i <= n;i++){
            pf[i] = pf[i - 1] + nums[i - 1];
            cout<<pf[i]<<" ";
            ans = max(ans,pf[i] - mn);
            mn = min(mn,pf[i]);
        }
        return ans;
    }
};
