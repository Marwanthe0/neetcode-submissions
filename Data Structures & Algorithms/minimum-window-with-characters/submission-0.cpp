class Solution {
public:
    bool check(multiset<char> ms,string b){
        for(auto c:b) {
            if(!ms.count(c)) return false;
            ms.erase(ms.find(c));
        }
        return true;
    }
    string minWindow(string s, string t) {
      int n = s.size();
      pair<int,int> ans = {0,n - 1};
      bool flag = false;
      for(int i = 0;i < n;i++){
        multiset<char> temp;
        for(int j = i;j < n;j++){
            temp.insert(s[j]);
            if(check(temp,t)) {
                if(j - i < ans.second - ans.first) ans = {i,j};
                flag = true;
            }
        }
      }
      if(flag){
        string last;
        for(int i = ans.first;i <= ans.second;i++) last.push_back(s[i]);
        return last;
      }
      return "";
    }
};
