class Solution {
public:
string a;
int n;
vector<int> dp;
int f(int i){
    if(i > n) return 0;
    if(i == n) return 1;
    if(dp[i] != -1) return dp[i];
    int ans = 0;
    if(a[i] != '0') ans += f(i + 1);
    if(a[i] == '1'){
        ans += f(i + 2);
    }
    if(a[i] == '2' && i + 1 < n && a[i + 1] <= '6'){
        ans += f(i + 2);
    }
    return dp[i] =  ans;
}
    int numDecodings(string s) {
        n = s.size();
        dp.assign(n + 1,-1);
        a = s;
        return f(0);
    }
};
