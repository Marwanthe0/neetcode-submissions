class Solution {
public:
    double myPow(double x, int n) {
        if(!n) return 1;
        double m = x;
        for(int i = 1;i < abs(n);i++){
            x *= m;
        }
        if(n >= 0)
            return x;
        else return 1/(x);
    }
};
