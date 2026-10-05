class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0,n = heights.size();
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                int amount = min(heights[i],heights[j])*(j - i);
                ans = max(ans,amount);
            }
        }
        return ans;
    }
};
