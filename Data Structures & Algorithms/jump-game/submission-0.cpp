class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),last = 0;
        for(int i = 0;i < n;i++){
            if(i == n - 1) return true;
            last = max(last,nums[i]);
            if(last <= 0) return false;
            last--;
        }
        return true;
    }
};
