class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto vl:nums){
            x = (x^vl);
        }
        return x;
    }
};
