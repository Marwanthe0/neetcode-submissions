class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1,r = *(max_element(piles.begin(),piles.end())),n = piles.size(),ans = r;
        auto answer = [&](int m){
            int count = 0;
            for(int i = 0;i < n;i++){
                count += (piles[i] / m) + (piles[i] % m != 0);
            }
            return count;
        };
        while(l <= r){
            int m = (r + l)/2;
            if(answer(m) <= h){
                ans = m,r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};
