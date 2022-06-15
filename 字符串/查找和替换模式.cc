// lc 890
class Solution {
public:
     bool isIsomorphic(string &s, string &t) {
        for (auto i = 0; i < s.size(); ++i)
        {
            if (s.find(s[i]) != t.find(t[i])) return false;
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ret;

        for (auto& i : words)
        {
            if (isIsomorphic(i, pattern)) ret.push_back(i);
        }

        return ret;
    }
};
