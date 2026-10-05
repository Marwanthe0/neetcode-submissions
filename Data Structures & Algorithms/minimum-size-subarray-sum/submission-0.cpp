class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0,r = 0,n = nums.size(),k = target,sum = 0,ans = nums.size();
        if(accumulate(nums.begin(),nums.end(),0) < k) return 0;
        while(r < n){
            sum += nums[r];
            if(sum >= k) ans = min(ans,r - l + 1);
            while(sum > k){
                sum -= nums[l++];
                if(sum >= k) ans = min(ans,r - l + 1);
            }
            r++;
        }
        return  ans;
    }
};