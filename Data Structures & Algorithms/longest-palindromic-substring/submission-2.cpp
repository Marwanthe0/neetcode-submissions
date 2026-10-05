class Solution {
   public:
    string longestPalindrome(string s) {
        string t = "@";

        for (char c : s) {
            t += '#';
            t += c;
        }

        t += "#$";

        int n = t.size();

        vector<int> p(n);

        int l = 0, r = 0;

        for (int i = 1; i < n - 1; i++) {
            int mirror = l + r - i;

            if (i < r) p[i] = min(r - i, p[mirror]);

            while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;

            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
        // cout<<t<<endl;
        int mx = *max_element(p.begin(),p.end());
        for(int i = 0;i < n;i++){
            // cout<<p[i]<<" ";
            if(p[i] == mx){
                string ans;
                // cout<<i<<endl;
                for(int j = i - 1,k = 1;k <= p[i];k++,j--){
                    if(t[j]!= '#') ans.push_back(t[j]);
                }
                reverse(ans.begin(),ans.end());
                if(t[i] != '#') ans.push_back(t[i]);
                for(int j = i + 1,k = 1;k <= p[i];k++,j++) {
                    if(t[j] != '#') ans.push_back(t[j]);
                }
                return ans;
            }
        }
        return "";
    }
};
