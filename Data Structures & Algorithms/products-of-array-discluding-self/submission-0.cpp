class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long checkzero = 0,prod = 1;
        vector<int> ans;
        for(auto vl:nums) {
            if(!vl) checkzero++;
            else prod *= vl;
        }
        if(checkzero){
            if(checkzero > 1){
                for(auto vl:nums) ans.push_back(0);
            }
            else{
                for(auto vl:nums){
                    if(!vl){
                        ans.push_back(prod);
                    }
                    else ans.push_back(0);
                }
            }
        }
        else{
            for(auto vl:nums){
                ans.push_back(prod/vl);
            }
        }
        return ans;
    }
};
