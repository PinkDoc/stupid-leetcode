// lc 378
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map<int, int> s;
        size_t count = 0;

        for (auto& i : matrix)
        for (auto j : i)
        {
            auto cand = j;

            if (count == k)
            {
                auto temp = *s.rbegin();
                if (cand < temp.first) 
                {
                    auto tn = temp.first;
                    s[temp.first]--;
                    if (s[tn] == 0) s.erase(tn);
                    s[cand]++;
                }
            }
            else
            {
                s[cand]++;
                count++;
            }

        }

        return (*s.rbegin()).first;
    }
};
