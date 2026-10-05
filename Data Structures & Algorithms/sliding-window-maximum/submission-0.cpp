class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int l = 0,r = 0;
        multiset<int> ms;
        while(r < n){
            ms.insert(nums[r]);
            if(r - l + 1 == k){
                ans.push_back(*(--ms.end()));
                ms.erase(ms.find(nums[l]));
                l++;
            }
            r++;
        }
        return ans;
    }
};
