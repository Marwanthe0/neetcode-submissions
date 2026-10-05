class Solution {
   public:
    int countSubstrings(string s) {
        string t = "@";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";
        int n = t.size(), l = 0, r = 0;
        vector<int> p(n, 0);
        for (int i = 1; i < n - 1; i++) {
            int mirror = l + r - i;
            if (i < r) p[i] = min(r - i, p[mirror]);
            while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i++) {ans += (p[i] + 1)/2;}
        return ans;
    }
};
