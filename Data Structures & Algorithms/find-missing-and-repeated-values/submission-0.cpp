class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int> m;
        int n = grid.size();
        for(auto vl:grid){
            for(auto val:vl) {
                m[val]++;
            }
        }
        vector<int> ans;
        int a,b;
        for(int i = 1;i <= n*n;i++){
            if(m[i] == 0) a = i;
            else if(m[i] == 2) b = i;
        }
        ans.push_back(b);        ans.push_back(a);

        return ans;
    }
};