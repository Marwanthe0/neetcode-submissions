class Solution {
public:
    int f(int i,vector<int> &cost,vector<int> &dp){
        if(i > cost.size()) return INT_MAX;
        if(i == cost.size()) return 0;
        if(dp[i] != -1)  return dp[i];
        return dp[i] =  cost[i] + min(f(i + 1,cost,dp),f(i + 2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1,-1);
        int zero = f(0,cost,dp);
        return min(dp[0],dp[1]);
    }
};
