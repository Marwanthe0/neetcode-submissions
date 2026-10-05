class Solution {
public:
    #define M 1000000007
vector<long long> fact = vector<long long>(101);
vector<long long> invfact = vector<long long>(101);
    long long mod(long long x,long long m = M){
        return x%m;
    }
    long long binexp(long long a,long long b){
        long long ans = 1ll;
        while(b){
            if(b&1ll) ans = mod(ans*1ll*a);
            a = mod(a*1ll*a);
            b >>= 1ll;
        }
        return mod(ans);
    }
    void fct(){
        fact[0] = invfact[0] = 1;
        for(int i = 1;i <= 100;i++){
            fact[i] = mod(fact[i - 1]*1ll*(i));
            invfact[i] = mod(binexp(fact[i],M-2ll));
        }
    }
    int nCr(int n,int r){
        long long nfact = mod(fact[n]),rfact = mod(invfact[r]),nrfact = mod(invfact[n - r]);
        return mod(mod(nfact*1ll*rfact)*1ll*nrfact);
    }
    int uniquePaths(int m, int n) {
        fct();
        return nCr(n + m - 2,m - 1);
    }
};
