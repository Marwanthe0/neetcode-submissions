class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),x = 0;
        for(int i = 0;i <=n;i++){
            x = (x^i);
        }
        for(auto vl:nums) x = (x^vl);
        return x;
    }
};
