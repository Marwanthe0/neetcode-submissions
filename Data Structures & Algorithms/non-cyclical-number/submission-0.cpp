class Solution {
public:
    bool isHappy(int n) {

    auto ss = [&](int n){
        long long sum = 0;
        while(n){
            sum += (n % 10)*(n % 10);
            n /= 10;
        }
        return sum;
    };
    map<int,int> m;
    while(n != 1){
        if(m.find(n) != m.end()) return false;
        m[n]++;
        n = ss(n);
    }
    return true;
    }
};
