class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0,r = 0,ans = 0,n = s.size(),size;
        map<int,int> st;
        while(r < n){
            st[s[r]]++;
            if(st.size()== r - l + 1){
                size = st.size();
                ans = max(ans,size);
            }
            while(st.size() != (r - l + 1) && l < r){
                st[s[l]]--;
                if(st[s[l]] <= 0) st.erase(s[l]);
                l++;
            }
            // size = st.size();
            ans = max(ans,int(st.size()));
            r++;
        }
        return ans;
    }
};
