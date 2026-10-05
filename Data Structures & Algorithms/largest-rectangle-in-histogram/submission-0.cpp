class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> v = {INT_MIN};
        for (auto vl : heights) v.push_back(vl);
        v.push_back(INT_MIN);
        n = v.size();
        stack<int> st;
        vector<int> front(n, 0), back(n, 0);
        for (int i = 0; i + 1 < n; i++) {
            while (st.size() && v[st.top()] >= v[i]) st.pop();
            if (st.size())
                front[i] = st.top();
            else
                front[i] = -1;
            st.push(i);
        }
        while (st.size()) st.pop();
        for (int i = n - 1; i > 0; i--) {
            while (st.size() && v[st.top()] >= v[i]) st.pop();
            if (st.size())
                back[i] = st.top();
            else
                back[i] = n;
            st.push(i);
        }
        int ans = 0;
        for (int i = 1; i + 1 < n; i++) {
            ans = max(ans,(i - front[i] + (back[i] - i) - 1)*v[i]);
            // cout <<i -  front[i] << " ";
        }
        // cout << endl;
        for (int i = 1; i + 1 < n; i++) {
            // cout << back[i] - i << " ";
        }
        // cout << endl;
        return ans;
    }
};
