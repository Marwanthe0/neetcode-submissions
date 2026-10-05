class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto vl:nums) s.insert(vl);
        return (s.size() != nums.size());
    }
};