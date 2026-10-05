class Solution {
public:
vector<int> v;
int n;
    int maxProduct(vector<int>& nums) {
        n = nums.size();
        v = nums;
        vector<int> pf(n,0),nval(n,0),pval(n,0);
        auto f = [&](int i,int j,int val){
            if(j < i || i < 0 || j < 0 || i >= n || j >= n) return INT_MIN;
            int count = pf[j] - (i?pf[i - 1]:0);
            // cout<<i<<" "<<j<<" "<<val<<" "<<count<<" "<<nval[i]<<" "<<pval[j]<<endl;
            if(count & 1){
                if(j - i + 1 == 1) return val;
                return max(val/nval[i],val/pval[j]);
            }
            return val;
        };
        int neg1 = -1,neg2 = n,tans = 1,x = 1,y = 1;
        for(int i = 0,j = n - 1;i < n;i++,j--){
            if(v[i] < 0) pf[i]++,x = v[i];
            else x *= v[i];
            if(i) pf[i] += pf[i - 1];
            pval[i] = x;

            if(v[j] < 0) y = v[j];
            else y *= v[j];
            nval[j] = y;
        }
        int ans = INT_MIN, last = 0;
        for(int i = 0;i < n;i++){
            if(!v[i])
            {
                ans = max(ans,0);
                ans = max(f(last,i - 1,tans),ans);
                last = i + 1,tans = 1;
            }
            else tans *= v[i];
        }
        if(last < n) ans = max(ans,f(last,n - 1,tans));
    return ans;
    }
};
