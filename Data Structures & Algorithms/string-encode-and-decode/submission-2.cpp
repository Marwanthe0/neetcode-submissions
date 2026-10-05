class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto vl:strs){
            s += vl;
            s += "\n";
        }
        reverse(s.begin(),s.end());
        return s;
    }

    vector<string> decode(string s) {
        reverse(s.begin(),s.end());
        vector<string> ans;
        string temp = "";
        int l = 0;
        while(l < s.size()){
            if(s[l] != '\n'){
                temp += s[l];
            }
            else {
                ans.push_back(temp);
                temp = "";
            }
            l++;
        }
        return ans;
    }
};
