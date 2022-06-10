
// O(n^2) 解法
class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 0) return "";
        
        string ret = strs[0];
        
        for (auto& i : strs)
        {
            auto riter = ret.begin();
            auto iiter = i.begin();
            while ( (riter != ret.end()) && (iiter != i.end()) && (*riter == *iiter))
            {
                riter++;
                iiter++;
            }
            string temp(ret.begin(), riter);
            ret = std::move(temp);
        }
        
        return ret;
    }
};

// O n
class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 0) return "";
        
        string ret = "";
        auto p = 0;
        while (true)
        {
            char ch = strs[0][p];
            bool fuck = false;
            for (auto& i : strs)
            {
                if (p >= i.size()|| ch != i[p]) return ret;
            }
            ret.push_back(ch);
            p++;
        }
        
        return ret;
    }
};
