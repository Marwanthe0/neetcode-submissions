class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        if(tokens.size() == 1) return stoi(tokens.front());
        for(auto c:tokens){
            if(c.back() >= '0' && c.back() <= '9'){
                st.push(stoi(c));
            }
            else{
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                switch(c[0]){
                    case '+': ans = x + y;break;
                    case '-': ans = y - x;break;
                    case '/': ans = (y / x);break;
                    case '*':ans = y*x;break;
                }
                st.push(ans);
            }
        }
        return ans;
    }
};
