// lc 205

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for (auto i = 0; i < s.size(); ++i)
        {
            if (s.find(s[i]) != t.find(t[i])) return false;
        }

        return true;
    }
};
