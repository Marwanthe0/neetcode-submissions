class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long n = 0;
        for(auto vl:digits){
            n *= 10;
            n += vl;
        }
        n++;
        vector<int> ans;
        while(n){
            ans.push_back(n % 10);
            n /= 10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
