class Solution {
public:
    int f(int i,vector<int> &v,vector<int> &dp){
        if(i < 0) return 0;
        if(i == 0) return v[i];
        if(dp[i] != -1) return dp[i];
        return dp[i] =  max(v[i] + f(i - 2,v,dp),f(i - 1,v,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1,-1);
        return f(n - 1,nums,dp);
    }
};
