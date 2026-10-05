class Solution {
public:
int n,m;
vector<pair<int,int>>  path = {{0,1},{1,0},{-1,0},{0,-1}};
bool valid(int i,int j) {return i >= 0 && j >= 0 && i < n && j < m;};
vector<vector<int>> v;
vector<vector<vector<int>>> dp;
int f(int i,int j,int last){
    if(v[i][j] <= last) return dp[i][j][last] = 0;
    if(dp[i][j][last]!= -1) return dp[i][j][last];
    int ans = 1;
    for(auto [x,y]:path){
        x += i,y += j;
        if(valid(x,y)){
            ans = max(ans,f(x,y,v[i][j]) + 1);
        }
    }
    return dp[i][j][last] = ans;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      n = matrix.size();
      m = matrix[0].size();
      v = matrix;
      int dist = 1;
      map<int,int> mp;
      set<int> st;
      for(auto &vl:v){
        for(auto &val:vl) {
            st.insert(val);
        }
      }
      for(auto vl:st) mp[vl] = dist++;
      for(auto &vl:v){
        for(auto &val:vl) {
            val = mp[val];
            // cout<<val<<" ";
            }
            // cout<<endl;
      }
      int ans = 1;
      dp.assign(n + 1,vector<vector<int>>(m + 1,vector<int>(dist + 1,-1)));
      for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
             ans = max(ans,f(i,j,0));
        }
      }
      return ans;
    }
};
