class Solution {
public:
    bool isValid(string s) {
        map<char,int> m = {{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};
        stack<int> st;
        for(auto c:s){
            if((!st.empty()) && st.top() == m[c]*(-1)){
                st.pop();
            }
            else if(m[c] < 0) return false;
            else st.push(m[c]);
        }
        return st.empty();
    }
};
