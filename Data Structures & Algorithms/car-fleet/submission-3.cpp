class Solution {
public:
    int lcm(int a,int b){return a*1ll*b/__gcd(a,b);}
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
      int n = speed.size();
      vector<pair<long long,long long>> v(n);
      long long ml = 1ll;
      for(int i = 0;i < n;i++){ 
        v[i] = make_pair(position[i],speed[i]);
       ml = lcm(ml,speed[i]);
       }
      sort(v.begin(),v.end());
      for(auto &[x,y]:v){ 
        x = target - x;
        x = x*1ll*ml;
        x = x/y;
        cout<<x<<" "<<y<<endl;
        }
        set<long long> s;
        long long last = INT_MAX;
        for(int i = n - 1;i >= 0;i--){
            if(last != INT_MAX && v[i].first < last) v[i].first = last;
            s.insert(v[i].first);
            last = v[i].first;
        }
        return (int)s.size();
    }
};
