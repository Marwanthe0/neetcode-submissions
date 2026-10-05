class Solution {
   public:
    string a, b;
    int n, m;
    vector<vector<int>> dp;
    int f(int i, int j) {
        if (j == m) return 1;
        if (i == n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int nimuna = f(i + 1, j), nimu = 0;
        if (a[i] == b[j]) nimu = f(i + 1, j + 1);
        return dp[i][j] = nimu + nimuna;
    }
    int numDistinct(string s, string t) {
        a = s, b = t;
        n = s.size(), m = t.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return f(0, 0);
    }
};
