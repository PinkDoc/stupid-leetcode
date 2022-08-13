class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1, 0);
        
        for (auto i = 1; i < n + 1; ++i)
        {
            ret[i] = ret[i / 2] + (i & 1);
        }


        return ret;
    }
};