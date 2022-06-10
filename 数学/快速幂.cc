// lc 204
class Solution {
public:
    
    bool isPrime(int n)
    {
        if (n <= 3) return n > 1;
        auto r = (int)std::sqrt(n) + 1;
        for (int i = 3; i <= r; i += 2)
        {
            if (n % i == 0 || n % 2 == 0) return false;
        }
        return true;
    }
    
    int countPrimes(int n) {
        int ret = 0;
        vector<bool> saves(n, true);
        for (int i = 0; i < n; ++i)
        {   
            if (i < 20000 &&i * i < n) saves[i * i] = false;
            if (saves[i] == false) continue;
            if (isPrime(i)) {
                ret++;
            }
        }
        return ret;
    }
};
