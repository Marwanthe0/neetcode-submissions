class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int,int>> s;
    int n = temperatures.size();
    vector<int> v(n,0);
    for(int i = 0;i < n;i++){
        int x = temperatures[i];
        while((!s.empty()) && x > s.top().first){
            v[s.top().second] = i - s.top().second;
            s.pop();
        }
        s.push({x,i});
    }
    return v;
    }
};
