class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums.front();
        vector<int> dp(n + 1,INT_MIN),dp2(n + 1,INT_MIN);
        vector<int> v(nums.begin(),nums.end()),v2(nums.begin() + 1,nums.end());
        v.pop_back();
        for(auto vl:v)cout<<vl<<" ";
        cout<<endl;
        for(auto vl:v2) cout<<vl<<" ";
        dp[0] = dp2[0] = 0;
        for(int i = 1;i < n;i++){
            int nibona = dp[i - 1],nibo = v[i - 1],nibona2 = dp2[i - 1],nibo2 = v2[i - 1];
            if(i > 1) {
                nibo = v[i - 1] + dp[i - 2];
                nibo2 = v2[i - 1]+dp2[i - 2];
            }
            dp[i] = max(nibo,nibona);
            dp2[i] = max(nibo2,nibona2);
        }
        return max(dp[n - 1],dp2[n - 1]);
    }
};
