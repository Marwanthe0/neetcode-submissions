class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(),ans = 0;
        for(int i = 0;i < n;){
            if(i == n - 1)break;
            else if(nums[i] + i == n - 1) {ans++;break;}
            pair<int,int> p = {nums[i + nums[i]],i + nums[i]};
            int k = 0;
            for(int j = i + nums[i];j > i;j--,k++){
                   if(nums[j] - k > p.first){
                       p = {nums[j] - k,j};
                   }
                }
            i = p.second;
            ans++;
        }
        return ans;
    }
};
