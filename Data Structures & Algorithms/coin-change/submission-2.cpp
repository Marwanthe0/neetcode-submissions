class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long long n = coins.size(),sum = amount;
        vector<vector<long long>> dp(n + 1,vector<long long>(sum + 1,1e12));
        dp[0][0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= sum;j++){
                long long nibona = dp[i - 1][j],nibo = 1e12;
                if(coins[i - 1] <= j){
                    nibo = 1 + dp[i][j - coins[i - 1]];
                }
                dp[i][j] = min(nibo,nibona);
            }
        }
        if(dp[n][sum] == 1e12) return -1;
        return (int)dp[n][sum];
    }
};
