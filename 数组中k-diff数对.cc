// lc 532
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<int> s;
        map<int, vector<int>> m;
        int ret = 0;
        for (auto i : nums)
        {
            int last = i - k;
            auto iter = s.find(last);
            if (iter != s.end()) 
            {
                int ok = 1;
                auto&& ref = m[i];
                for (auto j : ref)
                {
                    if (j == last) ok = 0;
                }
                ret += ok;
                if (ok == 1) ref.push_back(last);
            }
            s.insert(i);
        }
        return ret;
    }
};
