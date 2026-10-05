class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        while(n >= 0 && digits[n] == 9){
            n--;
        }
        vector<int> v;
        if(n < 0){
            v.push_back(1);
            for(int i = 0;i < digits.size();i++) v.push_back(0);
            return v;
        }
        else {
            digits[n]++;
            for(int i = n + 1;i < digits.size();i++) digits[i] = 0;
        }
        return digits;
    }
};
