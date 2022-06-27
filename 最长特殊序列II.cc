class Solution {
public:

    bool is_son(string& m,string& n)
    {
        auto p = 0;
        for (auto i = 0;i < n.size() ; ++i)
        {
            if (m[p] ==  n[i]) p++;
            if (p == m.size()) return true;
        }

        return false;
    }

    int findLUSlength(vector<string>& strs) {
        int ret = -1;

        for (auto i = 0 ; i < strs.size(); ++i)
        {
            bool is = false;
            for (auto j = 0; j < strs.size(); ++j)
            {
                if (i  == j) continue;
                if (!is)
                {
                    is = is_son(strs[i], strs[j]);
                }
            }
            if (!is)
            {
                ret = max(ret,  static_cast<int>(strs[i].size()));
            }
        }

        return ret;
    }
};
