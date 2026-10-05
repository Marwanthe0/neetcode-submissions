class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       map<char,int> ms1,ms2;
       int l = 0,r = 0,n = s1.size(),m = s2.size();
       for(auto c:s1) ms1[c]++;
       while(r < m){
        ms2[s2[r]]++;
        if(r - l + 1 == n){
            if(ms2 == ms1) return true;
           ms2[s2[l]]--;
           if(ms2[s2[l]] <= 0) ms2.erase(s2[l]);
            l++;
        }
        r++;
       }
       return false;
    }


};
