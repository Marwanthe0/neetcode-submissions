class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string s = text1;
        string t = text2;
        int n = s.size(),m = t.size();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        return dp[n][m];
        string ans;
        int l = n,r = m;
        while(l > 0 && r > 0){
            if(s[l - 1] == t[r - 1]) ans.push_back(s[l - 1]),l--,r--;
            else if(dp[l - 1][r] > dp[l][r - 1]) l--;
            else r--;
        }
    }
};
