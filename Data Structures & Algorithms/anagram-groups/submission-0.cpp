class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<string,vector<string>> m;
      for(auto str:strs){
        string x = str;
        sort(x.begin(),x.end());
        m[x].push_back(str);
      }
      vector<vector<string>> ans;
      for(auto [x,v]:m){
        vector<string> temp;
        for(auto vl:v){
            temp.push_back(vl);
        }
        ans.push_back(temp);
      }
      return ans;
    }
};
