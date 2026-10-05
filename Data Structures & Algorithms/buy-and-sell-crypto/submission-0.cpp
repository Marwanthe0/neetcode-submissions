class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),h = prices.back(),ans = 0;
        for(int i = n - 2;i >= 0;i--){
            h = max(h,prices[i]);
            if(prices[i] < h){
                ans = max(ans,h - prices[i]);
            }
        }
        return ans;
    }
};
