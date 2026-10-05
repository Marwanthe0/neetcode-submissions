class Solution {
public:
int n,m,o;
string a,b,s;
vector<vector<int>> dp;
bool f(int i,int j){
    int k = i + j;
    if(k == o) return true;
    if(dp[i][j] != -1) return dp[i][j];
    bool ans = false;
    if(i < n && a[i] == s[k]) ans |= f(i + 1,j);
    if(j < m && b[j] == s[k]) ans |= f(i,j + 1);
    return dp[i][j] = ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size(),m = s2.size(),o = s3.size();
        if(n+m != o) return false;
        dp.assign(n + 1,vector<int>(m + 1,-1));
        a = s1,b = s2,s = s3;
        return f(0,0);
    }
};
