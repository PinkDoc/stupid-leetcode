// lc 406
class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> fucker;
        for(auto i :s)
        {
            fucker[i]++;
        }

        bool has = false;

        int ret = 0;

        for (auto&i : fucker)
        {
            if (i.second % 2 == 1)
            {
                ret = has ? ret : ret + 1;
                has = has ? has : !has;
                if (i.second > 1)
                    ret += (i.second - 1);
            }
            else
            {
                ret += i.second;
            }
        }

        return ret;
    }
};
