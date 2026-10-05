class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0,n = height.size();
        vector<int> prevg(n + 1,-1),nextg(n + 1,n);
        vector<int> v = height,t = height;
        stack<int> st;
        for(int i = 0;i < n;i++){
            while(st.size() && v[st.top()] < v[i]) st.pop();
            if(st.size()) prevg[i] = ((prevg[st.top()] != -1)?prevg[st.top()]:st.top());
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i = n - 1;i >= 0;i--){
            while(st.size() && v[st.top()] < v[i]) st.pop();
            if(st.size()) nextg[i] = ((nextg[st.top()] != n)?nextg[st.top()]:st.top());
            st.push(i);
        }
        for(int i = 0;i < n;i++){
            if(prevg[i] != -1) prevg[i] = v[prevg[i]] - v[i];
            else prevg[i] = 0;
            // cout<<prevg[i]<<" ";
        }
        // cout<<endl;
        for(int i= 0;i < n;i++){
            if(nextg[i] == n) nextg[i] = 0;
            else nextg[i] = v[nextg[i]] - v[i];
            // cout<<nextg[i]<<" ";cout<<endl;
            }
        int uttor = 0;
        for(int i = 0;i < n;i++) uttor += min(prevg[i],nextg[i]);
        return uttor;
    }
};
