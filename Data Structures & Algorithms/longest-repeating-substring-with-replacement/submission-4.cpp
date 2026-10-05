class Solution {
public:
    int characterReplacement(string s, int k) {
        int count = 0,ds = 0,ans = 0,last = 0,i = 0,n = s.size();
        for(char c = 'A';c <= 'Z';c++){
            ds = k,count = 0;
            for(auto ch:s){
                if(ch == c){
                    if(count == 0) {last = i;}
                    count++;
                }
                else if(count > 0 && ds > 0){
                    ds--,count++;

                }
                else count = 0,ds = k;
                ans = max(ans,count+ min(ds,last));
                i++;
            }
            string t = s;
            reverse(t.begin(),t.end());
            ds = k,count = 0,last = 0,i = n - 1;
            for(auto ch:t){
                if(ch == c){
                    if(count == 0){last = i;}
                    count++;
                }
                else if(count > 0 && ds > 0){
                    ds--,count++;
                }
                else count = 0,ds = k;
                ans = max(ans,count + min(ds,(n - 1) - last));
                i--;
            }
        }
        return ans;
    }
};
