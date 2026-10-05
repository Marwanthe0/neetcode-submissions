class Solution {
public:
    int change(int amount, vector<int>& coins) {
        long long n = coins.size(),sum = amount;
        vector<vector<long long>> dp(n + 1,vector<long long>(sum + 1,0));
        dp[0][0] = 1;
        // for(auto vl:coins){
        //     dp[1][vl] = 1;
        // }
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= sum;j++){
                long long nibona = dp[i - 1][j],nibo = 0;
                if(coins[i - 1] <= j){
                    nibo = dp[i][j - coins[i - 1]];
                }
                dp[i][j] = nibo + nibona;
            }
        }
        return (int)dp[n][sum];
    }
};
