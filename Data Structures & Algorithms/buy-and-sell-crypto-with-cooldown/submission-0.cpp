class Solution {
public:
    int f(int i,vector<int> &v,bool buy,vector<vector<int>> &dp){
        if(i >= v.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            return dp[i][buy] =  max(f(i + 1,v,buy,dp),f(i + 1,v,!buy,dp) - v[i]);
        }
        else return dp[i][buy] =  max(f(i + 1,v,buy,dp),f(i + 2,v,!buy,dp)+v[i]);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int>(2,-1));
        return f(0,prices,1,dp);
    }
};
