class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(auto c:s){ 
            if((c >= 'a' && c <= 'z')){
                t += c;
            }
            else if(c >= 'A' && c <= 'Z'){
                t += ((c - 'A') + 'a');
            }
            else if(c >= '0' && c <= '9') t+= c;
       } 
       int l = 0,r = t.size() - 1;
        cout<<t<<endl;
        while(l < r){
            if(t[l] != t[r]){
            return false;
            }
            l++,r--;
        }
        return true;
    }
};
